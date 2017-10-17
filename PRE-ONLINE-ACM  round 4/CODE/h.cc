#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main(){
								int nv,ne;
								int S,T;

								scanf("%d %d",&nv,&ne);
								scanf("%d %d",&S,&T);

								vector<vector<pair<int,pair<int,int> > > > adj;
								vector<int> visited;

								for(int i=0; i<nv; i++)
																visited.push_back(0);

								for(int i=0; i<ne; i++)
																adj.push_back(vector<pair<int,pair<int,int> > >());

								for(int i=0; i<ne; i++) {
																int a,b,c,d;
																scanf("%d %d %d %d",&a,&b,&c,&d);
																adj[a].push_back(make_pair(b,make_pair(c,d)));
																adj[b].push_back(make_pair(a,make_pair(c,d)));
								}

								priority_queue<pair<pair<int,int>,pair<int,int> > > pq;
								pq.push(make_pair(make_pair(0,0),make_pair(0,S)));

								while(1) {
																pair<pair<int,int>,pair<int,int> > x = pq.top();
																pq.pop();
																int wlevel = -x.first.first;
																int wetdist = -x.first.second;
																int dist = -x.second.first;
																int node = x.second.second;

																visited[node] = 1;

																if(node==T) {
																								printf("%d %d %d",wlevel,wetdist,dist);
																								return 0;
																}

																for(int i=0; i<adj[node].size(); i++) {
																								int nextnode = adj[node][i].first;
																								int nextdist = adj[node][i].second.first;
																								int nextlevel = adj[node][i].second.second;

																								if(visited[nextnode]==1) continue;

																								int maxwlevel = wlevel;
																								if(maxwlevel<nextlevel) maxwlevel = nextlevel;

																								int nextwet = 0;
																								if(nextlevel!=0) nextwet = nextdist;

																								pq.push(make_pair(make_pair(-maxwlevel,-wetdist-nextwet),make_pair(-dist-nextdist,nextnode)));
																}
								}

}
