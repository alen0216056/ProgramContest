#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int pos, int len, vector<int>& v)
{
    bool dir = 1;
    int pos_l = -2147483646, pos_r=*(upper_bound(v.begin(), v.end(), pos+len)-1);
    len -= pos_r-pos;
    while( pos_l!=pos_r)
    {
        if( dir )
            pos_l = *lower_bound(v.begin(), v.end(), pos_r-len);
        else
            pos_r = *(upper_bound(v.begin(), v.end(), pos_l+len)-1);

        if( pos_l==pos_r )
            return pos_l;

        if( (len/(pos_r-pos_l))&1 )
            dir = !dir;

        len %= pos_r-pos_l;
    }
    return pos_l;
}

int main()
{
    int n, m, index, len, i, tmp;
    while( scanf("%d%d", &n, &m)==2 )
    {
        map<int, int> m1;
        vector<int> sort_v, v;
        for( i=0; i<n; i++ )
        {
            scanf("%d", &tmp);
            sort_v.push_back( tmp );
            v.push_back( tmp );
            m1[tmp] = i+1;
        }
        sort(sort_v.begin(), sort_v.end());

        while( m-- )
        {
            scanf("%d%d", &index, &len);
            printf("%d\n", m1[solve(v[index-1], len, sort_v)]);
        }
    }
    return 0;
}
