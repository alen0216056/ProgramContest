#include <iostream>
#include <vector>
using namespace std;

long long int two(int n)
{
    if( n==-1 )
        return 0;
    if( n==0 )
        return 1;
    return 2*two(n-1);
}

int main()
{
    long long int n, m;

    while( cin>>n && cin>>m )
    {
        vector<int> head, tail;

        for(int i=1; i<=n; i++)
        {
            if( m>( two(n-i-1) ) )
            {
                m -= two(n-i-1);
                tail.push_back(i);
            }
            else
                head.push_back(i);
        }
        for(int i=0; i<head.size(); i++)
            cout<<head[i]<<" ";
        for(int i=tail.size()-1; i>=0; i--)
            cout<<tail[i]<<" ";
        cout<<endl;
    }

    return 0;
}

