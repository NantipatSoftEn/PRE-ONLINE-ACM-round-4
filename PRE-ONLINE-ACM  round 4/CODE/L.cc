#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

char split[1010][1010];

int compare(char* str1, char* str2){
								int start1=0,start2=0;
								while(start1<strlen(str1) && str1[start1]=='0') start1++;
								while(start2<strlen(str2) && str2[start2]=='0') start2++;

								if(strlen(str1)-start1>strlen(str2)-start2) return 1;
								if(strlen(str1)-start1<strlen(str2)-start2) return -1;

								while(start1<strlen(str1) && start2<strlen(str2)) {
																if(str1[start1]>str2[start2]) return 1;
																if(str1[start1]<str2[start2]) return -1;
																start1++;
																start2++;
								}

								return 0;
}

int main (){
								char input[1010];
								scanf("%s",input);

								// split by .

								int row = 0, col = 0;
								for(int i=0; i<strlen(input); i++) {
																if(input[i]=='.') {
																								split[row][col] = '\0';
																								row++;
																								col = 0;
																}
																else{
																								split[row][col] = input[i];
																								col++;
																}
								}
								split[row][col] = '\0';
								row++;
								split[row][col] = '\0';
								row++;

								// find max

								char maxfront[1010] = "\0", maxback[1010] = "\0";
								for(int i=0; i<row-1; i++) {
																//cout << "-" << split[i] << "-" << split[i+1] << "-" << endl;
																if(strlen(split[i])!=0 && strlen(split[i+1])!=0) {
																								if(compare(split[i],maxfront)==1) {
																																strcpy(maxfront,split[i]);
																																strcpy(maxback,split[i+1]);
																								}
																								else if(compare(split[i],maxfront)==0 && strcmp(split[i+1],maxback)>0) {
																																strcpy(maxfront,split[i]);
																																strcpy(maxback,split[i+1]);
																								}
																}
																else if(strlen(split[i])!=0 && strlen(split[i+1])==0) {
																								if(compare(split[i],maxfront)==1) {
																																strcpy(maxfront,split[i]);
																																strcpy(maxback,"");
																								}
																}
																//cout << "current#" << maxfront << "#" << maxback << "#" << endl;
								}

								int start,end = strlen(maxback)-1;
								while(maxfront[start]=='0') start++;
								while(end>=0 && maxback[end]=='0') end--;

								for(int i=start; i<strlen(maxfront); i++)
																printf("%c",maxfront[i]);
								if(end!=-1) {
																printf(".");
																for(int i=0; i<=end; i++)
																								printf("%c",maxback[i]);
								}
								printf("\n");

								// find min

								int found = 0;
								int pos = -1, num = 100;
								for(int i = 0; i<row-1; i++) {
																if(strlen(split[i])>0 && split[i][strlen(split[i])-1]=='0' && strlen(split[i+1])>0) {
																								for(int j=0; j<strlen(split[i+1]); j++)
																																if(split[i+1][j]!='0') {
																																								if(j>pos || (j==pos && split[i+1][j]-'0'<num)) {
																																																found = 1;
																																																pos = j;
																																																num = split[i+1][j]-'0';
																																								}
																																								break;
																																}
																}
								}

								if(found==0) {
																for(int i=1; i<=9; i++) {
																								for(int j=0; j<strlen(input); j++) {
																																if(input[j]!='.' && input[j]-'0'==i) {
																																								printf("%d",i);
																																								return 0;
																																}
																								}
																}
								}
								else{
																printf("0.");
																for(int i=0; i<pos; i++)
																								printf("0");
																printf("%d",num);
								}
}
