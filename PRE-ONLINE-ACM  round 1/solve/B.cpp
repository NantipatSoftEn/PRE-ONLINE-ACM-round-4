#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
	map<string,int>mp;
	mp["2"] = 2;
	mp["3"] = 3;
	mp["4"] = 4;
	mp["5"] = 5;
	mp["6"] = 6;
	mp["7"] = 7;
	mp["8"] = 8;
	mp["9"] = 9;
	mp["10"] = 10;
	mp["A"] = 1;
	mp["J"] = 10;
	mp["Q"] = 10;
	mp["K"] = 10;
	

	int n;
	string a,b,c,d,e;
	cin >> n;
	for(int i=0;i<n;i++){
		int sum=0;
		cin >> a >> b >> c >> d >> e;
		int num[5] = {mp[a],mp[b],mp[c],mp[d],mp[e]};
		for(int j=0;j<5;j++){
			if(i==0||i==1||i==2)
			sum+=num[j];
			if(j>2 && sum>=16){
				if(sum+num[j+1]<21)
					sum+num[j+1];
				else
					continue;
			}
			
		}		
		if(sum>=21)
			cout << "busted\n";
		else
			cout << sum << endl;
	}	
}
