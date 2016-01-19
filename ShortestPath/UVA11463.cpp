#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int t, n, r, from, to, dis[2][105];
bool road[105][105];

void bfs(int s, int index)
{
    vector<bool> v(n, 0);
    queue<int> q;
    q.push(s);
    v[s] = 1;
    dis[index][s] = 0;

    while( !q.empty() )
    {
        int tmp = q.front();
        q.pop();
        for(int i=0; i<n; i++)
            if( road[tmp][i] && !v[i] )
            {
                v[i] = 1;
                q.push( i );
                dis[index][i] = dis[index][tmp] + 1;
            }
    }
}

int main()
{
    scanf("%d", &t);
    for(int c=1; c<=t; c++)
    {
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                road[i][j] = 0;

        scanf("%d", &r);
        while( r-- )
        {
            scanf("%d%d", &from, &to);
            road[from][to] = 1;
            road[to][from] = 1;
        }
        scanf("%d%d", &from, &to);

        bfs(from, 0);
        bfs(to, 1);

        int ans = 0;
        for(int i=0; i<n; i++)
            ans = ( dis[0][i]+dis[1][i]>ans )? dis[0][i]+dis[1][i]: ans;

        printf("Case %d: %d\n", c, ans);
    }
    return 0;
}
