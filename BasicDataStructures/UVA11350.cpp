#include <iostream>
#include <string>
using namespace std;

int main()
{
    long long int ncase, l_son, l_mom, r_son, r_mom, ans_son, ans_mom;
    string s;
    cin>>ncase;

    while( ncase-- )
    {
        cin>>s;

        l_son = 0;
        l_mom = 1;
        r_son = 1;
        r_mom = 0;
        ans_son = 1;
        ans_mom = 1;

        for( int i=0; i<s.length(); i++ )
        {
            if( s[i]=='L' )
            {
                r_son = ans_son;
                r_mom = ans_mom;
            }
            else
            {
                l_son = ans_son;
                l_mom = ans_mom;
            }
            ans_son = r_son + l_son;
            ans_mom = r_mom + l_mom;
        }
        cout<<ans_son<<"/"<<ans_mom<<endl;
    }
    return 0;
}
