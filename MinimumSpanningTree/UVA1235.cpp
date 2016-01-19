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

int roll(int x, int y)
{
    int ans = 0;
    for(int i=1000; i>0; i/=10)
    {
        ans += ( x/i>y/i )? min( (x/i-y/i), 10-(x/i-y/i) ): min( (y/i-x/i), 10-(y/i-x/i) );
        x %= i;
        y %= i;
    }
    return ans;
}

int t, n, from, to, weight, input[505];

int main()
{
    scanf("%d", &t);
    while( t-- )
    {
        int ans = 0, shortes = 40, tmp;
        bool start = 1;

        scanf("%d", &n);
        priority_queue<edge> pq;
        vector<int> p(n+1, -1);

        input[0] = 0;
        for(int i=1; i<=n; i++)
            scanf("%d", &input[i]);

        for(int i=1; i<=n; i++)
            if( roll(input[0], input[i])<shortes )
            {
                shortes = roll(input[0], input[i]);
                tmp = i;
            }
        merge(p, 0, tmp);
        ans += shortes;

        for(int i=1; i<=n; i++)
            for(int j=i+1; j<=n; j++)
                pq.push( edge(roll(input[i], input[j]), i, j) );

        while( !pq.empty() )
        {
            edge e = pq.top();
            pq.pop();
            if( find(p, e.f)!=find(p, e.t) )
            {
                merge(p, e.f, e.t);
                ans += e.w;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
