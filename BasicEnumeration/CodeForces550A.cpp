#include <iostream>
#include <string>
using namespace std;

bool solve1(string s)
{
    int i;

    for(i=0; i<s.length(); i++)
    {
        if( s[i]=='A' && s[i+1]=='B' )
        {
            i+=2;
            break;
        }
    }

    for(; i<s.length(); i++)
        if( s[i]=='B' && s[i+1]=='A' )
            return 1;
    return 0;
}

bool solve2(string s)
{
    int i;

    for(i=0; i<s.length(); i++)
    {
        if( s[i]=='B' && s[i+1]=='A' )
        {
            i+=2;
            break;
        }
    }

    for(; i<s.length(); i++)
        if( s[i]=='A' && s[i+1]=='B' )
            return 1;
    return 0;
}

int main()
{
    string s;

    while( cin>>s )
    {
        if( solve1(s) || solve2(s) )
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
