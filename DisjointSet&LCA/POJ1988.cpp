#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> p(30001, -1), child(30001, 0), deep(30001, 0);

int find(int x)
{
    if( p[x]==-1 )
        return x;

    int tmp = p[x];
    p[x] = find(p[x]);
    deep[x] += deep[tmp];
    return p[x];
}

void merge(int x, int y)
{
    int x_top = find(x), y_top = find(y);

    if( x_top!=y_top )
    {
        p[y_top] = x_top;
        deep[y_top] = child[x_top] + 1;
        child[x_top] += (child[y_top] + 1);
    }
}

int main()
{
    char c;
    int n, a, b;

    scanf("%d", &n);
    while( n-- )
    {
        scanf(" %c", &c);
        if( c=='M' )
        {
            scanf("%d %d", &a, &b);
            merge(a, b);
        }
        else
        {
            scanf("%d", &a);
            printf("%d\n", child[find(a)]-deep[a]);
        }
    }
    return 0;
}
