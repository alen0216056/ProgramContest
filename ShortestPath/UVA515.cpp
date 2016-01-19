#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct edge
{
    int start, end, d;
};

int main()
{
    int n, m, from, to, dis, tmp;
    string s;

    while( scanf("%d", &n) && n!=0 )
    {
        scanf("%d", &m);

        edge graph[m];
        for(int i=0; i<m; i++)
        {
            cin>>from>>to>>s>>dis;

            if( s=="gt" )
            {
                graph[i].start = from + to;
                graph[i].end = from - 1;
                graph[i].d = -dis - 1;
            }
            else
            {
                graph[i].start = from - 1;
                graph[i].end = from + to;
                graph[i].d = dis - 1;
            }
        }

        vector<int> sd(n+1, 0);

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if( sd[graph[j].start] + graph[j].d < sd[graph[j].end] )
                    sd[graph[j].end] = sd[graph[j].start] + graph[j].d;

        bool flag = 0;
        for(int j=0; j<m && !flag; j++)
            if( sd[graph[j].start] + graph[j].d < sd[graph[j].end] )
                flag = 1;

        if( flag )
            printf("successful conspiracy\n");
        else
            printf("lamentable kingdom\n");
    }
    return 0;
}
