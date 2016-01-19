#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n, pre, sum, buffer[100010];

    while( scanf("%d", &n)==1 )
    {
        int ans = 2147483647, count[205] = {0}, half, energy;
        pair<int, int> p;
        vector< pair<int, int> > table;
        map<int, int> large_cost;

        for( int i=0; i<n; i++ )
        {
            scanf("%d", &buffer[i]);
        }
        for( int i=0; i<n; i++ )
        {
            p.first = buffer[i];
            scanf("%d", &p.second);
            table.push_back( p );
        }

        sort(table.begin(), table.end());

        pre = table[n-1].first;
        sum = table[n-1].second;
        large_cost[pre] = 0;
        for(int i=n-2; i>=0; i--)
        {
            if( table[i].first!=pre )
            {
                pre = table[i].first;
                large_cost[pre] = sum;
            }
            sum += table[i].second;
        }

        pre = table[0].first;
        half = 1;
        energy = 0;
        for(int i=1; i<n; i++)
        {
            if( pre==table[i].first )
            {
                half++;
            }
            else
            {
                energy += large_cost[pre];
                if( (i-half)>=half )
                {
                    int cut = i+1-2*half;
                    for(int j=1; j<=200; j++)
                    {
                        if(cut>count[j])
                        {
                            energy += count[j]*j;
                            cut -= count[j];
                        }
                        else
                        {
                            energy += cut*j;
                            break;
                        }
                    }
                }

                if( ans>energy )
                    ans = energy;

                for(int j=i-1; j>=0; j--)
                {
                    if( pre!=table[j].first )
                        break;
                    count[table[j].second]++;
                }

                pre = table[i].first;
                half = 1;
                energy = 0;
            }
        }
        if( (n-half)>=half )
        {
            int cut = n+1-2*half;
            for(int j=1; j<=200; j++)
            {
                if(cut>count[j])
                {
                    energy += count[j]*j;
                    cut -= count[j];
                }
                else
                {
                    energy += cut*j;
                    break;
                }
            }
        }
        if( ans>energy )
            ans = energy;
        cout<<ans<<endl;
    }
    return 0;
}
