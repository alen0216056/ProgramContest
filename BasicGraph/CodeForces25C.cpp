#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, k, from, to, weight, sp[305][305];
    long long int sum;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d", &sp[i][j]);

    scanf("%d", &k);
    while( k-- )
    {
        scanf("%d%d%d", &from, &to, &weight);
        sum = 0;
        if( weight<sp[from][to] )
        {
            sp[from][to] = weight;
            sp[to][from] = weight;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if( sp[i][from]+sp[from][to]+sp[to][j]<sp[i][j] )
                    sp[i][j] = sp[i][from]+sp[from][to]+sp[to][j];
                if( sp[i][to]+sp[to][from]+sp[from][j]<sp[i][j] )
                    sp[i][j] = sp[i][to]+sp[to][from]+sp[from][j];
                sum += sp[i][j];
            }
        }
        printf("%lld ", sum/2);
    }
    printf("\n");
    return 0;
}
