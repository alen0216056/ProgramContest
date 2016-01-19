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
    int n, a, b, c;

    scanf("%d", &n);
    vector<int> p(2*n, -1);
    while( scanf("%d%d%d", &c, &a, &b) && !(a==0 && b==0 && c==0) )
    {
        switch(c)
        {
            case 1:
                if( find(a+n, p)==find(b, p) )
                    printf("-1\n");
                else
                {
                    merge(a, b, p);
                    merge(a+n, b+n, p);
                }
                break;
            case 2:
                if( find(a, p)==find(b, p) )
                    printf("-1\n");
                else
                {
                    merge(a, b+n, p);
                    merge(a+n, b, p);
                }
                break;
            case 3:
                if( find(a, p)==find(b, p) )
                    printf("1\n");
                else
                    printf("0\n");
                break;
            case 4:
                if( find(a, p)==find(b+n, p) )
                    printf("1\n");
                else
                    printf("0\n");
                break;
        }
    }
    return 0;
}
