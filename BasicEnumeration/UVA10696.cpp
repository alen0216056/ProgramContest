#include <iostream>
using namespace std;

int main()
{
    int n;
    while( cin>>n && n!=0)
    {
        cout<<"f91("<<n<<") = ";
        if( n<=100 )
            cout<<"91"<<endl;
        else
            cout<<n-10<<endl;
    }
    return 0;
}
