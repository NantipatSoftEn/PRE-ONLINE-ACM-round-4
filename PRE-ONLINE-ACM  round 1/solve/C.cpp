#include<iostream>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	int a[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> a[i][j];
		}
	}
	int b[n][m]
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]>0)	b[i][j] = a[i][j];
			if(a[i][j]==0){
				if(i==0 && j==0)
					b[i][j] = (a[i+1][j] + a[i][j+1]) /2;
				else if(i==n-1 && j==0)
					b[i][j] = (a[i-1][j] + a[i][j+1]) /2;
				else if(i==0 && j==m-1)
					b[i][j] = (a[i][j-1] + a[i+1][j]) /2;
				else if(i==n-1 && j==m-1)
					b[i][j] = (a[i][j-1] + a[i-1][j]) /2;
				else if(i==0)
					b[i][j] = (a[i][j-1] + a[i+1][j] + a[i][j+1]) /3;
				else if(j==0)
					b[i][j] = (a[i+1][j] + a[i][j+1] + a[i-1][j]) /3;
				else if(i==n-1)
					b[i][j] = (a[i+1][j] + a[i][j+1]) /2;
				else if(j==m-1)
					b[i][j] = (a[i+1][j] + a[i][j+1]) /2;
				else
					b[i][j] = (a[i+1][j] + a[i][j+1]) /2;
			}	
			
		}
	}
	
	return 0;
}
