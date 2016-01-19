#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

class compare
{
public:
    bool operator()(pair<long long int, int> a, pair<long long int, int> b)
    {
        if( a.first==b.first )
            return a.second>b.second;
        return a.first>b.first;
    }
};

int n, m, from, to, weight;
vector< pair<int, int> > graph[100005];
vector<int> ans;
priority_queue< pair<long long int, int>, vector< pair<long long int,  int> >, compare > q;
long long int dis[100005], minimum;
int parent[100005] = {0};
bool visited[100005] = {0};

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++)
    {
        scanf("%d%d%d", &from, &to, &weight);
        graph[from].push_back(make_pair(to, weight));
        graph[to].push_back(make_pair(from, weight));
    }
    for(int i=2; i<=n; i++)
        dis[i] = 1e11;

    dis[1] = 0;
    q.push( make_pair(dis[1], 1) );
    for(int i=0; i<n; i++)
    {
        from = q.top().second;
        q.pop();
        visited[from] = 1;
        for(int j=0; j<graph[from].size(); j++)
        {
            to = graph[from][j].first;
            weight = graph[from][j].second;
            if( !visited[to] && dis[from]+weight<dis[to] )
            {
                dis[to] = dis[from] + weight;
                q.push( make_pair(dis[to], to) );
                parent[to] = from;
            }
        }
    }

    from = parent[n];
    ans.push_back(n);
    while( from!=0 )
    {
        ans.push_back(from);
        from = parent[from];
    }
    if( ans[ans.size()-1]==1 )
    {
        for(int i=ans.size()-1; i>=0; i--)
            printf("%d ", ans[i]);
        printf("\n");
    }
    else
        printf("-1\n");
    return 0;
}
