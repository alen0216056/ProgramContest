#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n, x[205], y[205], p[205];
double w[205][205], d[205];
bool v[205];

double dis(int x1, int y1, int x2, int y2)
{
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

int main(void)
{
    for(int ncase=1; scanf("%d", &n) && n!=0 ; ncase++)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d %d", &x[i], &y[i]);
            d[i] = 0x7FFFFFF;
            v[i] = false;
        }

        for(int i=0; i<n; i++)
        {
            w[i][i] = 0;
            for(int j=i+1; j<n; j++)
            {
                w[i][j] = dis(x[i], y[i], x[j], y[j]);
                w[j][i] = dis(x[i], y[i], x[j], y[j]);
            }
        }

        d[0] = 0;
        p[0] = -1;
        for(int i=0; i<n; i++)
        {
            int from = -1, to = -1;
            double min = 0x7FFFFFFF;

            for(int j=0; j<n; j++)
                if( !v[j] && d[j]<min )
                {
                    from = j;
                    min = d[j];
                }

            if( from==-1 )
                break;

            v[from] = true;
            for(to=0; to<n; to++)
                if( !v[to] && w[from][to]<d[to] )
                {
                    d[to] = w[from][to];
                    p[to] = from;
                }
        }

        double ans = 0;
        int tmp = 1;
        do{
            ans = (w[p[tmp]][tmp]>ans)? w[p[tmp]][tmp]: ans;
            tmp = p[tmp];
        }while( tmp!=0 );

        printf("Scenario #%d\n", ncase);
        printf("Frog Distance = %.3f\n", ans);
        printf("\n");
    }

	return 0;
}
