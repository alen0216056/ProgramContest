#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n, m, from, to;

    while( scanf("%d %d", &n, &m) && !(n==0 && m==0) )
    {
        vector<int> graph[101];
        int in[101] = {0};
        bool complete[101] = {0};

        for(int i=0; i<m; i++)
        {
            scanf("%d %d", &from, &to);
            graph[from].push_back(to);
            in[to]++;
        }

        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                if( in[i]==0 && !complete[i] )
                {
                    for(int j=0; j<graph[i].size(); j++)
                    {
                        in[graph[i][j]]--;
                    }
                    complete[i] = 1;
                    printf("%d ", i);
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
