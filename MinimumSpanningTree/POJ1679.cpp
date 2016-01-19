#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int t, n, m, from, to, weight, x[105], y[105];

struct edge
{
    int f, t, w;
    edge(int _w, int _f, int _t):w(_w), f(_f), t(_t){}

    bool operator<(const edge& e1) const
    {
        return w<e1.w;
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

int special_mst(vector<edge>& g, int not_use)
{
    int ans = 0, c = 0;
    vector<int> p(n+1, -1);

    for(int i=0; i<not_use; i++)
        if( find(p, g[i].f)!=find(p, g[i].t) )
        {
            merge(p, g[i].f, g[i].t);
            ans += g[i].w;
            c++;
        }

    for(int i=not_use+1; i<g.size(); i++)
        if( find(p, g[i].f)!=find(p, g[i].t) )
        {
            merge(p, g[i].f, g[i].t);
            ans += g[i].w;
            c++;
        }

    return ( c==(n-1) )? ans: -1;
}

int main()
{
    scanf("%d", &t);
    while( t-- )
    {
        scanf("%d %d", &n, &m);

        bool flag = 1;
        int ans = 0;
        vector<edge> g;
        vector<int> p(n+1, -1), used;

        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d", &from, &to, &weight);
            g.push_back( edge(weight, from, to) );
        }
        sort(g.begin(), g.end());

        for(int i=0; i<g.size(); i++)
            if( find(p, g[i].f)!=find(p, g[i].t) )
            {
                merge(p, g[i].f, g[i].t);
                ans += g[i].w;
                used.push_back(i);
            }

        for(int i=0; i<used.size(); i++)
            if( ans==special_mst(g, used[i]) )
            {
                flag = 0;
                break;
            }
        if( flag )
            printf("%d\n", ans);
        else
            printf("Not Unique!\n");
    }
    return 0;
}
