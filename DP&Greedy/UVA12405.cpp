#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int ncase, n, ans;
    char buf[110];

    scanf("%d", &ncase);
    for(int i=1; i<=ncase; i++)
    {
        ans = 0;

        scanf("%d", &n);
        scanf("%s", buf);

        for(int i=0; i<n; i++)
        {
            if(buf[i]=='.')
            {
                ans ++;
                i += 2;
            }
        }

        printf("Case %d: %d\n", i, ans);
    }
    return 0;
}
