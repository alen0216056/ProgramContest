#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;

    while( cin>>n && n!=0 )
    {
        if( n==1 )
        {
            cout<<"Discarded cards:"<<endl;
            cout<<"Remaining card: 1"<<endl;
        }
        else
        {
            queue<int> q;
            for(int i=1; i<=n; i++)
                q.push( i );

            cout<<"Discarded cards: "<<q.front();

            q.pop();
            q.push( q.front() );
            q.pop();

            while( q.size()!=1 )
            {
                cout<<", "<<q.front();
                q.pop();
                q.push( q.front() );
                q.pop();
            }
            cout<<endl;
            cout<<"Remaining card: "<<q.front()<<endl;
        }
    }
    return 0;
}
