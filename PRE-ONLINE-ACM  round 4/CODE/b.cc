#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long gcd(long a, long b){
								if(b==0) return a;
								return gcd(b,a%b);
}
int main() {
								long n,g,k,z=0, t;
								cin >> n;
								int arr[n];
								for(int i = 0; i < n; i++) {
																cin >> arr[i] >> t;
																z += t;
								}
								g = z;
								for (int i = 0; i < n; i++) {
																g = gcd(g,arr[i]);
								}
								cout << g << endl;
								return 0;
}
