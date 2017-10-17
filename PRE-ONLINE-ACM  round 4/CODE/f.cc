#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define check(x)  if(!(x)) { fprintf(stderr, #x); return -1; }

typedef struct snode {
								char c;
								struct snode* left;
								struct snode* right;
								int fv;
								int M[1024];
} node;

int c2n(char x) {
								switch(x) {
								case 'm': case 'M': return 1;
								case 'o': case 'O': return 2;
								case 'b': case 'B': return 4;
								case 'i': case 'I': return 8;
								case 'l': case 'L': return 16;
								case 'e': case 'E': return 32;
								case 'n': case 'N': return 64;
								case 'p': case 'P': return 128;
								case 'a': case 'A': return 256;
								case 'r': case 'R': return 512;
								}
								printf("x");
}

node* parse(char s[],int i,int j) {
								node* p = (node*)malloc(sizeof(node));
								p->c = s[i];
								for(int k=0; k<1024; k++)
																p->M[k] = -1;
								if('a'<=s[i] && s[i]<='z') {
																p->left = NULL;
																p->right = NULL;
																p->fv = c2n(p->c);
								}
								else if('A'<=s[i] && s[i]<='Z') {
																p->left = parse(s,i+1,j);
																p->right = NULL;
																p->fv = p->left->fv & (1023-c2n(p->c));
								}
								else {
																int x=1,k=i+1;
																for(; k<=j; k++) {
																								if('a'<=s[k] && s[k]<='z')
																																x--;
																								else if(s[k]=='+')
																																x++;
																								if(x==0)
																																break;
																}
																p->left = parse(s,i+1,k);
																p->right = parse(s,k+1,j);
																p->fv = p->left->fv | p->right->fv;
								}
								return p;
}

int maxp(node* p,int s) {
								if(p->M[s] != -1)
																return p->M[s];
								else if('a'<=p->c && p->c<='z')
																p->M[s] = 0;
								else if('A'<=p->c && p->c<='Z')
																p->M[s] = maxp(p->left,s & (1023-c2n(p->c)));
								else if('A'<=p->left->c && p->left->c<='Z' && (p->right->fv & s) == 0) {
																// reduce
																int r = 1 + maxp(p->left->left, s | c2n(p->left->c));
																// not reduce
																int r1 = maxp(p->left,s);
																int r2 = maxp(p->right,s);
																p->M[s] = r>r1+r2 ? r : r1+r2;
								}
								else {
																int r1 = maxp(p->left,s);
																int r2 = maxp(p->right,s);
																p->M[s] = r1+r2;
								}
								return p->M[s];
}

int main() {
								char s[10010];
								int i;
								scanf("%s",s);
								check(strlen(s)<=10000)
								for(i=0; i<strlen(s); i++)
																if(s[i]!='+')
																								c2n(s[i]);
								node* root = parse(s,0,strlen(s)-1);
								printf("%d\n",maxp(root,0));
								return 0;
}
