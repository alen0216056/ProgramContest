#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int  n, m;

bool test(double len, vector<int>& v)
{
    int count = 1;
    double pos = v[0] + len;
    for(int i=0; i<v.size(); i++)
    {
        if( (pos+len)<v[i] )
        {
            pos = v[i] + len;
            count++;
            if( count>n )
                return 0;
        }
    }
    return 1;
}

double bsearch( vector<int>& v, double l, double r )
{
    if( (r-l)<0.01 )
        return r;
    double mid = (l+r)/2.0;

    if( test(mid, v) )
        return bsearch(v, l, mid);
    else
        return bsearch(v, mid, r);
}

int main()
{
    int ncase, tmp;

    scanf("%d", &ncase);

    while( ncase-- )
    {
        vector<int> v;
        scanf("%d%d", &n, &m);

        while( m-- )
        {
            scanf("%d", &tmp);
            v.push_back( tmp );
        }
        sort(v.begin(), v.end());

        printf("%.1f\n", bsearch(v, 0, v[v.size()-1]-v[0]));
    }
    return 0;
}
