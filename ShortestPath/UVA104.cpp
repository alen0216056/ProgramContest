#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, parent[25][25][25];
    double rate[25][25][25];

    while( scanf("%d", &n)==1 )
    {
        bool flag = 0;
        vector<int> ans;

        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if( i==j )
                    rate[0][i][j] = 1.0;
                else
                    scanf("%lf", &rate[0][i][j]);

        for(int i=1; i<=n && !flag; i++)
        {
            for(int j=1; j<=n; j++)
                for(int k=1; k<=n; k++)
                    rate[i][j][k] = 0.0;


            for(int j=1; j<=n; j++)
                for(int k=1; k<=n; k++)
                    for(int l=1; l<=n; l++)
                        if( rate[i-1][j][k]*rate[0][k][l]>rate[i][j][l] )
                        {
                            rate[i][j][l] = rate[i-1][j][k]*rate[0][k][l];
                            parent[i][j][l] = k;
                        }

            for(int j=1; j<=n; j++)
            {
                if( rate[i][j][j]>1.01 )
                {
                    int tmp = j;
                    for(int k=i; k>=0; k--)
                    {
                        ans.push_back(tmp);
                        tmp = parent[k][j][tmp];
                    }
                    ans.push_back(j);
                    flag = 1;
                    break;
                }
            }
        }


        if( flag )
        {
            printf("%d", ans[ans.size()-1]);
            for(int i=ans.size()-2; i>=0; i--)
                printf(" %d", ans[i]);
            printf("\n");
        }
        else
            printf("no arbitrage sequence exists\n");
    }
    return 0;
}
