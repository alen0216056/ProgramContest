#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n, l, buf[1001];
    double max;
    while( cin>>n && cin>>l )
    {
        for( int i=0; i<n; i++ )
            cin>>buf[i];
        sort( buf, buf+n );

        max = ( buf[0]==0 )? 0: buf[0];
        for( int i=1; i<n; i++)
            if( (buf[i]-buf[i-1])/2.0>max )
                max = (buf[i]-buf[i-1])/2.0;
        if( buf[n-1]!=l && l-buf[n-1]>max )
            max = l-buf[n-1];

        printf("%f\n", max);
    }
    return 0;
}
