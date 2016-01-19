#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, m, i, j, k, l, tmp, ans;
    int buf[110][110] = {0};

    while( scanf("%d %d", &n, &m)==2 && ( n!=0 && m!=0 ) )
    {
        tmp = ans = 0;

        for( i=1; i<=n; i++ )
        {
            for( j=1; j<=m; j++ )
            {
                scanf("%d", &buf[i][j]);
                buf[i][j] += buf[i-1][j] + buf[i][j-1] - buf[i-1][j-1];
            }
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                for(int k=0 ;k<i; k++)
                {
                    for(int l=0; l<j; l++)
                    {
                        if( ( buf[i][j] - buf[i][l] - buf[k][j] + buf[k][l] )==0 )
                        {
                            tmp = ( i-k ) * ( j-l );
                            ans = ( tmp>ans )? tmp: ans;
                        }
                    }
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
