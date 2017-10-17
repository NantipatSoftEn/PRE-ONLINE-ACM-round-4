#include<iostream>

using namespace std;

int main(){
	int a,b,x,y;
	cin >> a >> x >> b >> y;
	int bs = b-y;
	int ansb = ((x+y)-b > 0)?b:x+y;
	int ansa = (x - bs<=0)?0:x-bs;
	cout <<  ansa << " " << ansb; 
	return 0;
	
}
