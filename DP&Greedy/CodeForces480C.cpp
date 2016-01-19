#include <iostream>
#include <cstdio>
using namespace std;

int n, a, b, k;
int dp[5010][5010] = {0};
long long dp2[5010] = {0}, tmp;

int main()
{
    while( scanf("%d%d%d%d", &n, &a, &b, &k)==4 )
    {
        if( a<b )
        {
            for(int i=1; i<b; i++)
                dp[1][i] = (b-i-1>=i)? b-2: 2*(b-i-1);

            for(int i=2; i<=k; i++)
            {
                for(int l=1; l<b; l++)
                    dp2[l] = dp2[l-1] + dp[i-1][l];

                for(int j=1; j<b; j++)
                {
                    int start = ( b-j-1>=j )? 1: 2*j-b+1;
                    tmp = dp2[b-1]-dp2[j] + dp2[j-1]-dp2[start-1];

                    dp[i][j] = tmp%1000000007;
                }
            }
            printf("%d\n", dp[k][a]);
        }
        else
        {
            dp[1][b] = 0;
            for(int i=b+1; i<=n; i++)
                dp[1][i] = (i-b-1>=n-i)? n-b-1: 2*(i-b-1);

            for(int i=2; i<=k; i++)
            {
                dp2[b] = 0;
                for(int l=b+1; l<=n; l++)
                    dp2[l] = dp2[l-1] + dp[i-1][l];

                for(int j=b+1; j<=n; j++)
                {
                    int end = ( j-b-1>=n-j )? n: 2*j-b-1;
                    tmp = dp2[end]-dp2[j] + dp2[j-1]-dp2[b];

                    dp[i][j] = tmp%1000000007;
                }
            }
            printf("%d\n", dp[k][a]);
        }
    }
    return 0;
}
