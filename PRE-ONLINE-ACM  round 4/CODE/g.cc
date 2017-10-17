#include <stdio.h>

int main(){
								int n;
								scanf("%d",&n);
								long long plus=0,accplus=0,minus=0,accminus=0,sum=0;
								for(int i=0; i<n; i++) {
																long long x;
																scanf("%lld",&x);

																sum+=x;

																accplus+=x;
																if(accplus<0) accplus=0;
																if(accplus>plus) plus=accplus;

																accminus-=x;
																if(accminus<0) accminus=0;
																if(accminus>minus) minus=accminus;
								}

								//printf("%lld %lld %lld\n",plus,minus,sum);

								if(plus>sum+minus)
																printf("%lld",plus);
								else
																printf("%lld",sum+minus);
}
