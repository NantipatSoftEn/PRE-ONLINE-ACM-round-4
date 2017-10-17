#include <iostream>
using namespace std;

int main() {
								int n,m,l;
								cin >> n >> m>> l;
								int arr[n][m];
								for(int i = 0; i < n; i++)
																for(int j = 0; j < m; j++)
																								arr[i][j] = 0;
								for (int i = 0; i < l; i++) {
																int a,b,c,d;
																cin>>a>>b>>c>>d;
																for(int x = a; x<=c; x++) {
																								for(int y = b; y <= d; y++) {
																																arr[x][y] = 1;
																								}
																}
								}
								int ans =0;
								for(int i = 0; i< n; i++) {
																for (int j = 0; j < m; j++) {
																								ans += arr[i][j];
																}
								}
								cout << ans << endl;
								return 0;
}
