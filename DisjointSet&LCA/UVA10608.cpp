#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int ncase, n, m, from, to;
    bool visited[30001];

    scanf("%d", &ncase);
    while( ncase-- )
    {
        scanf("%d%d", &n, &m);

        int ans = 0;
        memset(visited, 0, 30001);
        vector< vector<int> > v(n+1);
        while( m-- )
        {
            scanf("%d%d", &from, &to);
            v[from].push_back(to);
            v[to].push_back(from);
        }

        for(int i=1; i<=n; i++)
        {
            if( !visited[i] )
            {
                int tmp = 1;
                queue<int> q;
                q.push(i);
                visited[i] = 1;
                while( !q.empty() )
                {
                    from = q.front();
                    q.pop();
                    for(int i=0; i<v[from].size(); i++)
                        if( !visited[v[from][i]] )
                        {
                            visited[v[from][i]] = 1;
                            q.push( v[from][i] );
                            tmp++;
                        }
                }
                ans = (ans>tmp)? ans: tmp;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
