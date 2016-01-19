#include <iostream>
#include <string.h>
using namespace std;

void solve( char* pre, char* in, int len )
{
    if( len>0 )
    {
        char* pos = strchr( in, pre[0] );
        int p = pos - in + 1;

        solve( pre+1, in, p-1 );
        solve( pre+p, in+p, len-p );
        cout<<pre[0];
    }
}

int main()
{
    int len;
    char pre[27], in[27];

    while( cin>>pre && cin>>in )
    {
        len = strlen( pre );
        solve( pre, in, len );
        cout<<endl;
    }
    return 0;
}
