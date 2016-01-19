#include <iostream>
using namespace std;

int tmp, buf[100005];

int bsearch(int l, int r)
{
    int mid = (l+r)/2;
    if( buf[mid]<tmp )
    {
        if( tmp<=buf[mid+1] )
            return mid;
        return bsearch(mid+1, r);
    }
    else
    {
        if( buf[mid-1]<tmp )
            return mid-1;
        return bsearch(l, mid-1);
    }
}

int main()
{
    int n, m;
    while( cin>>n )
    {
        buf[0] = 0;
        for( int i=1; i<=n; i++ )
        {
            cin>>buf[i];
            buf[i] = buf[i-1] + buf[i];
        }
        cin>>m;
        while( m-- )
        {
            cin>>tmp;
            cout<<bsearch(0, n)+1<<endl;
        }
    }
    return 0;
}
