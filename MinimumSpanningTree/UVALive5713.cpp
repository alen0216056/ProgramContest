#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int t, n, from, to, weight, x[1005], y[1005], p[1005];

struct edge
{
    int f, t;
    double w;
    edge(double _w, int _f, int _t):w(_w), f(_f), t(_t){}

    bool operator<(const edge& e) const
    {
        return w<e.w;
    }
};

int find(vector<int>& parent, int x)
{
    return (parent[x]==-1)? x: parent[x]=find(parent, parent[x]);
}

void merge(vector<int>& parent, int x, int y)
{
    parent[find(parent, x)] = find(parent, y);
}

double dis(int x1, int y1, int x2, int y2)
{
    return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) );
}

void dfs(vector< vector< pair<int, double> > >& g,  vector< vector<double> >& d, vector<bool>& v, int start, int pre, double diff)
{
    d[start][pre] = diff;
    for(int i=0; i<g[pre].size(); i++)
        if( !v[g[pre][i].first] )
        {
            v[g[pre][i].first] = 1;
            dfs(g, d, v, start, g[pre][i].first, max(diff, g[pre][i].second));
        }
}

int main()
{
    scanf("%d", &t);
    while( t-- )
    {
        scanf("%d", &n);
        double ans = 0, all = 0;
        vector<edge> g;
        vector<int> parent(n, -1), used;
        vector< vector< pair<int, double> > > mst(n);
        vector< vector<double> > d(n, vector<double>(n));

        for(int i=0; i<n; i++)
            scanf("%d %d %d", &x[i], &y[i], &p[i]);

        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                g.push_back( edge(dis(x[i], y[i], x[j], y[j]), i, j) );
        sort(g.begin(), g.end());

        for(int i=0; i<g.size(); i++)
            if( find(parent, g[i].f)!=find(parent, g[i].t) )
            {
                merge(parent, g[i].f, g[i].t);
                all += g[i].w;
                used.push_back(i);
            }

        for(int i=0; i<used.size(); i++)
        {
            mst[g[used[i]].f].push_back( pair<int, double>(g[used[i]].t, g[used[i]].w) );
            mst[g[used[i]].t].push_back( pair<int, double>(g[used[i]].f, g[used[i]].w) );
        }

        for(int i=0; i<n; i++)
        {
            vector<bool> v(n, 0);
            dfs(mst, d, v, i, i, 0);
        }

        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
            {
                if( (p[i]+p[j])/(all-d[i][j])>ans )
                    ans = (p[i]+p[j])/(all-d[i][j]);
            }

        printf("%.2f\n", ans);
    }
    return 0;
}
