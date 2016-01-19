#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int ncase, n, m, i, j;
    pair<int, int> tmp;

    scanf("%d", &ncase);
    for( i=0; i<ncase; i++ )
    {
        if( i )
            printf("\n");

        int left = 0, right = 0, index = -1;
        vector< pair<int, int> > line, ans;

        scanf("%d", &m);
        while( scanf("%d %d", &tmp.first, &tmp.second)==2 && (tmp.first!=0 || tmp.second!=0) )
        {
            line.push_back( tmp );
        }
        sort(line.begin(), line.end());

        for( j=0; j<line.size(); j++ )
        {
            for(; j<line.size() && line[j].first<=left; j++ )
            {
                if( line[j].second>right )
                {
                    right = line[j].second;
                    index = j;
                }
            }

            if( index==-1 )
                break;

            ans.push_back( line[index] );
            left = right;
            j--;
            if( left>=m )
                break;
        }

        if( left>=m )
        {
            printf("%d\n", ans.size());
            for( j=0; j<ans.size(); j++ )
                printf("%d %d\n", ans[j].first, ans[j].second);
        }
        else
            printf("0\n");
    }
    return 0;
}
