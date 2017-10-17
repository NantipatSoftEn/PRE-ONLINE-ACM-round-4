#include<iostream>
#include<string>
using namespace std;

int main(){
	string num;
	cin >> num;
	int count=0;
	for(int i=0;i<num.length();i++){
		if(num[i]=='0'||num[i]=='6'||num[i]=='4'||num[i]=='9')
			count++;
		if(num[i]=='8')
			count+=2;
	}
	cout << count;
	return 0;
}
