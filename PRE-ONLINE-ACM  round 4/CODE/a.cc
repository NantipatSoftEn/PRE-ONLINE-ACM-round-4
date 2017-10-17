#include <stdio.h>
#include <string.h>

char x[100010];
int main(){
								int a=0,ac=0,acm=0,acmi=0,acmic=0,acmicp=0,acmicpc=0;
								scanf("%s",x);
								for(int i=0; i<strlen(x); i++) {
																if(x[i]=='A')
																								a=(a+1)%1000000007;
																if(x[i]=='C') {
																								ac=(ac+a)%1000000007;
																								acmic=(acmic+acmi)%1000000007;
																								acmicpc=(acmicpc+acmicp)%1000000007;
																}
																if(x[i]=='M')
																								acm=(acm+ac)%1000000007;
																if(x[i]=='I')
																								acmi=(acmi+acm)%1000000007;
																if(x[i]=='P')
																								acmicp=(acmicp+acmic)%1000000007;
								}
								printf("%d",acmicpc);
}
