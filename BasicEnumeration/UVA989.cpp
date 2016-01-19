#include <iostream>
using namespace std;

int n, m[9][9];

bool solve(int x, int y)
{
    if( x==n*n )
    {
        for(int i=0; i<n*n; i++)
        {
            for(int j=0; j<n*n; j++)
            {
                if( j )
                    cout<<" ";
                cout<<m[i][j];
            }
            cout<<endl;
        }
        return 1;
    }


    if( !m[x][y] )
    {
        int i, j, k, l;
        bool row[10]={0}, col[10]={0}, matrix[10]={0};

        for(i=0; i<n*n; i++)
        {
            row[m[x][i]] = m[x][i] ? 1 : 0;
            col[m[i][y]] = m[i][y] ? 1 : 0;
        }

        i = ( x<n ) ? 0 : ( x<2*n ) ? n : n*2;
        j = ( y<n ) ? 0 : ( y<2*n ) ? n : n*2;
        for(k=0; k<n; k++)
            for(l=0; l<n; l++)
                matrix[m[i+k][j+l]] = m[i+k][j+l] ? 1 : 0;

        for(k=1; k<=n*n; k++)
        {
            if( !row[k] && !col[k] && !matrix[k] )
            {
                m[x][y] = k;

                i = ( y==(n*n-1) ) ? x+1 : x;
                j = ( y==(n*n-1) ) ? 0 : y+1;
                if( solve(i, j) )
                    return 1;

                m[x][y] = 0;
            }
        }
        return 0;
    }
    else
    {
        int i, j;
        i = ( y==(n*n-1) ) ? x+1 : x;
        j = ( y==(n*n-1) ) ? 0 : y+1;
        if( solve(i, j) )
            return 1;
        else
            return 0;
    }
}

int main()
{
    int count = 0;
    while( cin>>n )
    {
        for(int i=0; i<n*n; i++)
            for(int j=0; j<n*n; j++)
                cin>>m[i][j];

        if( count )
            cout<<endl;

        if( !solve(0, 0) )
            cout<<"NO SOLUTION"<<endl;

        count++;
    }
    return 0;
}
