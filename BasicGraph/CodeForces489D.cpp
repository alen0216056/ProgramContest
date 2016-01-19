#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool g[3005][3005] = {0};

int main()
{
    vector<int> graph[3005];
    int n, m, from, to, mid, tmp, ans = 0;

    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++)
    {
        scanf("%d%d", &from, &to);
        graph[from].push_back(to);
        g[from][to] = 1;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            tmp = 0;
            if( i==j )
                continue;

            for(int k=0; k<graph[i].size(); k++)
            {
                mid = graph[i][k];
                if( g[mid][j] )
                    tmp++;
            }
            if(tmp>1)
                ans += tmp*(tmp-1)/2;
        }
    }
    printf("%d\n", ans);
    return 0;
}
