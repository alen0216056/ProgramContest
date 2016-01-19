#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct edge
{
    int f, t;
    double w;
    edge(double _w, int _f, int _t):w(_w), f(_f), t(_t){}

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

double dis(int x1, int y1, int x2, int y2)
{
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

int n, m, from, to, x[800], y[800];

int main()
{
    while( scanf("%d", &n)!=EOF )
    {
        int c= 0;
        double ans = 0;
        vector<int> p(n+1, -1);

        for(int i=1; i<=n; i++)
            scanf("%d %d", &x[i], &y[i]);

        priority_queue<edge> pq;
        for(int i=1; i<=n; i++)
            for(int j=i+1; j<=n; j++)
                pq.push( edge(dis(x[i], y[i], x[j], y[j]), i, j) );

        scanf("%d", &m);
        while( m-- )
        {
            scanf("%d %d", &from, &to);
            if( find(p, from)!=find(p, to) )
            {
                merge(p, from, to);
                c++;
            }
        }

        while( c<n && !pq.empty() )
        {
            edge e = pq.top();
            pq.pop();
            if( find(p, e.f)!=find(p, e.t) )
            {
                merge(p, e.f, e.t);
                ans += e.w;
                c++;
            }
        }
        printf("%.2f\n", ans);
    }
    return 0;
}
