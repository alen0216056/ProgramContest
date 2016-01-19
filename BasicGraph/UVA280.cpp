#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main()
{
    int n, m, from, to, ans[101], ans_n;

    while( scanf("%d", &n) && n!=0)
    {
        bool graph[101][101] = {0};
        while( scanf("%d", &from) && from!=0 )
        {
            while( scanf("%d", &to) && to!=0)
                graph[from][to] = 1;
        }

        scanf("%d", &m);
        for(int i=0; i<m; i++)
        {
            bool visited[101] = {0};
            queue<int> q;

            scanf("%d", &from);
            q.push(from);
            while( !q.empty() )
            {
                from = q.front();
                for(int j=1; j<=n; j++)
                {
                    if( graph[from][j] && !visited[j] )
                    {
                        q.push(j);
                        visited[j] = 1;
                    }
                }
                q.pop();
            }
            ans_n = 0;
            for(int j=1; j<=n; j++)
            {
                if( !visited[j] )
                {
                    ans[ans_n] = j;
                    ans_n++;
                }
            }
            printf("%d", ans_n);
            for(int j=0; j<ans_n; j++)
                printf(" %d", ans[j]);
            printf("\n");
        }
    }
    return 0;
}
