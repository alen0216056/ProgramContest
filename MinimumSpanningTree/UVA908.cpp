#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct edge
{
    int w, f, t;
    edge(int _w, int _f, int _t):w(_w), f(_f), t(_t){}

    bool operator<(const edge& e1) const
    {
        return w>e1.w;
    }
};

int find(vector<int>& p, int x)
{
    return (p[x]==-1)? x: p[x]=find(p, p[x]);
}

void merge(vector<int>& p, int x, int y)
{
    p[find(p, x)] = find(p, y);
}

int n, m, k, from, to, weight;

int main()
{
    for(int ncase = 0; scanf("%d", &n)!=EOF; ncase++)
    {
        int ans1 = 0, ans2 = 0;

        priority_queue<edge> g;
        vector<int> p(n+1, -1);

        for(int i=0; i<n-1; i++)
        {
            scanf("%d %d %d", &from, &to, &weight);
            ans1 += weight;
            g.push( edge(weight, from, to) );
        }

        scanf("%d", &k);
        while( k-- )
        {
            scanf("%d %d %d", &from, &to, &weight);
            g.push( edge(weight, from, to) );
        }

        scanf("%d", &m);
        while( m-- )
        {
            scanf("%d %d %d", &from, &to, &weight);
        }

        while( !g.empty() )
        {
            edge e = g.top();
            g.pop();

            if(find(p, e.f)!=find(p, e.t))
            {
                merge(p, e.f, e.t);
                ans2 += e.w;
            }
        }
        if( ncase )
            printf("\n");
        printf("%d\n", ans1);
        printf("%d\n", ans2);
    }
    return 0;
}
