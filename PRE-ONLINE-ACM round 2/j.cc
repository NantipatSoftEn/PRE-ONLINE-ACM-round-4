#include<iostream>
#include<cstdio>
using namespace std;
struct st
{
    int x,y;
    int c;
};
char map[1010][1010];
char cheak[1010][1010];
struct st q[1000100];
int qt=0,qr=0;
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i= 0 ; i< n ;i++)
    {
        cin >> map[i];
    }
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    sx--,sy--,tx--,ty--;
    q[qr].x = sx;
    q[qr].y = sy;
    q[qr].c = 0;
    check[sx][sy] = 1;
    qr++;
    int ans = -1;
    while(qf < qr)
    {
        int cx = q[qf].x;
        int cy = q[qf].y;
        int cc =c[qf].c;

        qf++;
        if(cx == tx && cy ==ty)
            ans == cc;
            break;
    }
    #define WALK(dx,dy) \

    return 0;
}
