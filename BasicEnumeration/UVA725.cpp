#include <iostream>
#include <iomanip>
using namespace std;

bool check(int n)
{
    int d[5];
    for(int i=0; i<5; i++)
    {
        d[i] = n%10;
        n /= 10;
    }

    for(int i=0; i<5; i++)
        for(int j=i+1; j<5; j++)
            if( d[i]==d[j] )
                return 0;
    return 1;
}

bool d_check(int n, int m)
{
    int d1[5], d2[5];
    for(int i=0; i<5; i++)
    {
        d1[i] = n%10;
        d2[i] = m%10;
        n /= 10;
        m /= 10;
    }

    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            if( d1[i]==d2[j] )
                return 0;
    return 1;
}

int main()
{
    int n;
    bool first = 0;
    while( cin>>n && n!=0)
    {
        if( first )
            cout<<endl;
        first = 1;
        bool flag = 1;
        int max = 99999/n;
        for(int i=1234; i<=max; i++)
        {
            if( check(i) && check(n*i) && d_check(i, n*i) )
            {
                cout<<n*i<<" / "<<setw(5)<<setfill('0')<<i<<" = "<<n<<endl;
                flag = 0;
            }
        }
        if( flag )
            cout<<"There are no solutions for "<<n<<"."<<endl;
    }
    return 0;
}
