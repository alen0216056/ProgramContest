#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n, m, i, j;

    while( cin>>n && n!=0 )
    {
        while( cin>>m && m!=0 )
        {
            int a[n], b[n];
            stack<int> s;

            a[0] = 1;
            b[0] = m;
            for( i=1; i<n; i++ )
            {
                a[i] = i+1;
                cin>>b[i];
            }

            for( i=n-1, j=n-1; i>=0 && j>=0; )
            {
                if( a[i]==b[j] )
                {
                    i--;
                    j--;
                    while( !s.empty() )
                    {
                        if( s.top()==a[i] )
                        {
                            s.pop();
                            i--;
                        }
                        else
                            break;
                    }
                }
                else
                {
                    s.push( b[j] );
                    j--;
                }
            }

            if( i==-1 )
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
