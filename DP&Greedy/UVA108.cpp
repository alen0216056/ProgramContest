#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, ans, tmp, DP[110][110] = {0};

    while( scanf("%d", &n)==1 && n>0 )
    {
        ans = 0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                scanf("%d", &DP[i][j]);
                DP[i][j] += DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1];
            }
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                for(int k=0 ;k<i; k++)
                {
                    for(int l=0; l<j; l++)
                    {
                        tmp = DP[i][j] - DP[i][l] - DP[k][j] + DP[k][l];
                        ans = (tmp>ans)? tmp: ans;
                    }
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
