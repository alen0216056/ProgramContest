#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n, w;
    int buf[200010];
    while( cin>>n && cin>>w )
    {
        for( int i=0; i<2*n; i++ )
            cin>>buf[i];
        sort( buf, buf+2*n );
        printf("%f\n", 3*n*min( min( buf[0]/1.0, buf[n]/2.0 ), w/(3.0*n) ));
    }
    return 0;
}
