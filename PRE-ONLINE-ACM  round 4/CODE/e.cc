#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
								int n,x,y;
								cin >> n >> x >> y;
								y = x-y;

								vector<int> v;
								for(int i=0; i<n; i++) {
																int t;
																cin >> t;
																v.push_back(-t);
								}
								sort(v.begin(),v.end());

								int ans = 0;

								if(x==0) {
																for(int i=0; i<v.size(); i++)
																								ans-=v[i];
								}
								else
																for(int i=0; i<v.size(); i++) {
																								if(i>=(n/x)*x) {
																																ans-=v[i];
																								}
																								else{
																																if(i%x<x-y)
																																								ans-=v[i];
																								}
																}

								cout << ans;
								return 0;
}
