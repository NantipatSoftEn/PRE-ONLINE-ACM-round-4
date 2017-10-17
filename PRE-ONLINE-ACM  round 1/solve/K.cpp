#include<iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=n-1;i>=0;i--){
		cin >> a[i]; 
	}
	int sh[n];
	sh[0] = 0;
	for(int i=1;i<n;i++){
		if(i-a[i]>=0)
			sh[i] = min(sh[i-1]+1,sh[i-a[i]]+1);
		else
			sh[i] = sh[i-1]+1;
	} 
	cout << sh[n-1];
	return 0;
}
