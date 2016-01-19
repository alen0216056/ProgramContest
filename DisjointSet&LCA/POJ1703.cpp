#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int find(int x, vector<int>& p)
{
    return ( -1==p[x] )? x: (p[x]=find(p[x], p));
}

void merge(int x, int y, vector<int>& p)
{
    if( find(y, p)!=find(x, p) )
    {
        p[find(y, p)] = find(x, p);
    }
}

int main()
{
    char c;
    int ncase, n, m, a, b;

    scanf("%d", &ncase);
    while( ncase-- )
    {
        scanf("%d%d", &n, &m);
        vector<int> p(2*n+1, -1);
        while( m-- )
        {
            scanf(" %c%d%d", &c, &a, &b);

            if( c=='A' )
            {
                if( find(a, p)==find(b, p) || find(a+n, p)==find(b+n, p) )
                    printf("In the same gang.\n");
                else if( find(a, p)==find(b+n, p) || find(a+n, p)==find(b, p) )
                    printf("In different gangs.\n");
                else
                    printf("Not sure yet.\n");
            }
            else
            {
                merge(a, b+n, p);
                merge(a+n, b, p);
            }
        }
    }

    return 0;
}
