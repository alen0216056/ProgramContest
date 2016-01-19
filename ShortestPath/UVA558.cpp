#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int c, n, m, from[2010], to[2010], weight[2010];

    scanf("%d", &c);
    while( c-- )
    {
        scanf("%d %d", &n, &m);
        for(int i=0; i<m; i++)
            scanf("%d%d%d", &from[i], &to[i], &weight[i]);

        vector<int> dis(n, 0);      //add a vertice, it's distance to every vectex is 0

        for(int i=1; i<n; i++)
            for(int j=0; j<m; j++)
                if( dis[from[j]] + weight[j]<dis[to[j]] )
                    dis[to[j]] = dis[from[j]] + weight[j];

        bool possible = 0;
        for(int j=0; j<m && !possible; j++)
            if( dis[from[j]] + weight[j]<dis[to[j]] )
                possible = 1;

        if( possible )
            printf("possible\n");
        else
            printf("not possible\n");
    }
    return 0;
}
