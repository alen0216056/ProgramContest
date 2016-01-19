#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int ncase, num, q, c, a, from, to, t, root;

void dfs2(vector< vector<int> >& g, vector<int>& tmp, vector<bool> v, int x)
{
    v[x] = 1;
    for(int i=0; i<g[x].size(); i++)
    {
        if( !v[g[x][i]] )
        {
            dfs2(g, tmp, v, g[x][i]);
            tmp[x] += tmp[g[x][i]];
        }
    }
}

void dfs(vector< vector<int> >& g, vector< vector<int> >& a, vector<int>& tin, vector<int>& tout, vector<bool>& v, int x, int px)
{
    v[x] = 1;
    t++;
    tin[x] = t;
    a[x][0] = px;
    for(int i=1; i<log2(num); i++)
        a[x][i] = a[ a[x][i-1] ][i-1];

    for(int i=0; i<g[x].size(); i++)
    {
        if( !v[g[x][i]] )
            dfs(g, a, tin, tout, v, g[x][i], x);
    }
    t++;
    tout[x] = t;
}

bool is_ancestor(vector<int>& tin, vector<int>& tout, int x, int y)
{
    return (tin[x]<=tin[y]) && (tout[x]>=tout[y]);
}

int lca(vector< vector<int> >& a, vector<int>& tin, vector<int>& tout, int x, int y)
{
    if( is_ancestor(tin, tout, x, y) )
        return x;
    if( is_ancestor(tin, tout, y, x) )
        return y;

    for(int i=log2(num); i>=0; i--)
    {
        if( !is_ancestor(tin, tout, a[x][i], y) )
            x = a[x][i];
    }
    return a[x][0];
}

int main()
{
    scanf("%d", &ncase);
    for(int i=1; i<=ncase; i++)
    {
        t = 0;
        scanf("%d", &num);
        vector<bool> visit(num+1, 0), visit2(num+1, 0);
        vector<int> tin(num+1), tout(num+1), tmp(num+1, 0);
        vector< vector<int> > graph(num+1), ancester(num+1, vector<int>(20, 0));

        for(int j=1; j<num; j++)
        {
            scanf("%d %d", &from, &to);
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        dfs(graph, ancester, tin, tout, visit, 0, 0);

        scanf("%d", &q);
        while( q-- )
        {
            scanf("%d %d %d", &from, &to, &c);
            a = lca(ancester, tin, tout, from, to);

            tmp[a] -= c;
            if( a!=ancester[a][0] )
                tmp[ancester[a][0]] -= c;
            tmp[from] += c;
            tmp[to] += c;
        }

        dfs2(graph, tmp, visit2, 0);
        printf("Case #%d:\n", i);
        for(int j=0; j<num; j++)
            printf("%d\n", tmp[j]);
    }
    return 0;
}
