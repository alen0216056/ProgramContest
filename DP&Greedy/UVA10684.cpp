#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, buf, tmp, ans;

    while( scanf("%d", &n)==1 && n!=0 )
    {
        tmp = 0;
        ans = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%d", &buf);

            if( tmp+buf>buf )
            {
                tmp += buf;
            }
            else
            {
                tmp = buf;
            }
            ans = (tmp>ans)? tmp: ans;
        }

        if( ans>0 )
            printf("The maximum winning streak is %d.\n", ans);
        else
            printf("Losing streak.\n");
    }
    return 0;
}
