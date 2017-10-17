#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
	string m[] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
	map<string,int>mp;
	mp["JAN"] =1;
	mp["FEB"]=2;
	mp["MAR"]=3;
	mp["APR"]=4;
	mp["MAY"]=5;
	mp["JUN"]=6;
	mp["JUL"]=7;
	mp["AUG"]=8;
	mp["SEP"]=9;
	mp["OCT"]=10;
	mp["NOV"]=11;
	mp["DEC"]=12;
	int a;
	string month;
	cin >> month;
	cin >> a;
	int timer = (mp[month]+(a%12))%12;
	if(timer < 0)
		cout << m[11+timer];
	else if(timer == 0)
		cout << m[11];
	else
		cout << m[timer-1];
	return 0;
}
