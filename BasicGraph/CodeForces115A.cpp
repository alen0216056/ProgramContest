#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n, m[2010], tmp, next, ans=0;

    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &m[i]);

    for(int i=1; i<=n; i++)
    {
        tmp = 1;
        next = m[i];
        while( next>0 )
        {
            next = m[next];
            tmp++;
        }
        ans = (tmp>ans)? tmp: ans;
    }
    printf("%d\n", ans);
    return 0;
}
