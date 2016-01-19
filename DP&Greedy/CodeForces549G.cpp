#include <iostream>
#include <algorithm>
using namespace std;

int buf[200005], ans[200005];

int main()
{
    int n, i;
    while( cin>>n )
    {
        for( i=0; i<n; i++ )
        {
            cin>>buf[i];
            buf[i] += i;
        }
        sort(buf, buf+n);

        ans[0] = buf[0];
        for( i=1; i<n; i++ )
        {
            if( buf[i]>buf[i-1] )
                ans[i] = buf[i] - i;
            else
                break;
        }
        if( i==n )
        {
            for( i=0; i<n; i++ )
                cout<<ans[i]<<" ";
            cout<<endl;
        }
        else
            cout<<":("<<endl;
    }
    return 0;
}
