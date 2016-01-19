#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

char buffer[8000000];

int abs( int n )
{
    return ( n<0 ) ? -n : n;
}

int main()
{
    int n, i;
    char c;

    while( gets(buffer)!=NULL )
    {
        vector<int> buf;
        stack<int> toy, vol;

        for( char* ptr = strtok(buffer, " "); ptr != NULL; ptr = strtok(NULL, " ") )
        {
            int x;
            sscanf( ptr, "%d", &x );
            buf.push_back( x );
        }

        toy.push( buf[0] );
        vol.push( abs(buf[0]) );

        for( i=1; i<buf.size(); i++ )
        {
            if( ( toy.top() + buf[i] )==0 )
            {
                toy.pop();
                vol.pop();
                if( toy.empty() )
                    break;
            }
            else if( buf[i]<0 && vol.top()>abs(buf[i]) )
            {
                vol.top() -= abs(buf[i]);
                toy.push( buf[i] );
                vol.push( abs(buf[i]) );
            }
            else
                break;
        }


        if( i==buf.size()-1 && toy.empty() && vol.empty() )
            printf(":-) Matrioshka!\n");
        else
            printf(":-( Try again.\n");
    }

    return 0;
}
