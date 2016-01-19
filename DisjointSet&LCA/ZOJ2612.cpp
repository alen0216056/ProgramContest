#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

void show(int x)
{
    long long int a = 0, b = 1;

    for(int i=0; i<x; i++)
    {
        a *= 2;
        b *= 2;
        if( b>=10000000000000000LL )
        {
            a++;
            b -= 10000000000000000LL;
        }
    }

    if( a==0 )
        printf("%lld\n", b);
    else
        printf("%lld%.16lld\n", a, b);
}

int pow(int x, int y, int r)
{
    if( y==0 )
        return 1;
    if( x==0 )
        return 0;

    int tmp = pow(x, y/2, r);
    tmp = (tmp*tmp)%r;
    return (y&1)? (tmp*x)%r: tmp;
}

int find(vector<int>& pre, int x)
{
    return (pre[x]==-1)? x: pre[x]=find(pre, pre[x]);
}

void merge(vector<int>& pre, int x, int y)
{
    if( find(pre, x)!=find(pre, y) )
       pre[find(pre, y)] = find(pre, x);
}

int main()
{
    int r, n, m, tmp, count;

    while( scanf("%d", &r) && r!=0 )
    {
        bool flag;
        vector< vector<bool> > visited(2, vector<bool>(r+5, 0));
        vector< vector<int> > pre(3, vector<int>(r+5, -1)), in(2, vector<int>(r+5, 0)), coef(2, vector<int>(105, 0)), value(2, vector<int>(105, 0));

        scanf("%d", &n);
        for(int i=n; i>=0; i--)
            scanf("%d", &coef[0][i]);
        scanf("%d", &m);
        for(int i=m; i>=0; i--)
            scanf("%d", &coef[1][i]);

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<=n; j++)
                value[0][i] += coef[0][j] * pow(i, j, r);
            value[0][i] %= r;
            in[0][value[0][i]]++;

            for(int j=0; j<=m; j++)
                value[1][i] += coef[1][j] * pow(i, j, r);
            value[1][i] %= r;
            in[1][value[1][i]]++;
        }

        for(int i=0; i<2; i++)
        {
            flag =1;
            while( flag )
            {
                flag = 0;
                for(int j=0; j<r; j++)
                    if( !visited[i][j] && in[i][j]==0 )
                    {
                        flag =1;
                        visited[i][j] = 1;
                        in[i][value[i][j]]--;
                        merge(pre[i], r, j);
                    }
            }

            for(int j=0; j<r; j++)
                if( !visited[i][j] )
                    merge(pre[i], j, value[i][j]);
        }

        for(int i=0; i<=r; i++)
        {
            merge(pre[2], find(pre[0], i), i);
            merge(pre[2], find(pre[1], i), i);
        }

        count = -1;
        for(int i=0; i<=r; i++)
            if( find(pre[2], i)==i )
                count++;
        show(count);
    }
    return 0;
}
