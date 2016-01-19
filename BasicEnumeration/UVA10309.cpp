#include <iostream>
#include <string.h>
using namespace std;

char buf[10][11] = {0};
int count;

bool check(char* ptr)
{
    for(int i=0; i<10; i++)
        if( ptr[i]=='O' )
            return 0;
    return 1;
}

void solve(int n, int take)
{
    if( n==10 )
    {
        int tmp_count = take;
        char tmp1[11], tmp2[11], tmp3[11];

        strcpy(tmp1, buf[0]);
        strcpy(tmp2, buf[1]);
        strcpy(tmp3, buf[2]);

        for(int i=0; i<7; i++)
        {
            for(int j=0; j<10; j++)
            {
                if( tmp1[j]=='O' )
                {
                    if( (j-1)>=0 )
                        tmp2[j-1] = (tmp2[j-1]=='O') ? '#' : 'O';
                    if( (j+1)<=9 )
                        tmp2[j+1] = (tmp2[j+1]=='O') ? '#' : 'O';
                    tmp2[j] = (tmp2[j]=='O') ? '#' : 'O';
                    tmp3[j] = (tmp3[j]=='O') ? '#' : 'O';

                    tmp_count++;
                }
            }
            strcpy(tmp1, tmp2);
            strcpy(tmp2, tmp3);
            strcpy(tmp3, buf[i+3]);
        }

        for(int i=7; i<=8; i++)
        {
            for(int j=0; j<10; j++)
            {
                if( tmp1[j]=='O' )
                {
                    if( (j-1)>=0 )
                        tmp2[j-1] = (tmp2[j-1]=='O') ? '#' : 'O';
                    if( (j+1)<=9 )
                        tmp2[j+1] = (tmp2[j+1]=='O') ? '#' : 'O';
                    tmp2[j] = (tmp2[j]=='O') ? '#' : 'O';
                    tmp3[j] = (tmp3[j]=='O') ? '#' : 'O';

                    tmp_count++;
                }
            }
            strcpy(tmp1, tmp2);
            strcpy(tmp2, tmp3);
        }

        if( check( tmp1 ) && tmp_count<count )
            count = tmp_count;
        return;
    }
    ////////////////////////////////////

    if( (n-1)>=0 )
        buf[0][n-1] = (buf[0][n-1]=='O') ? '#' : 'O';
    if( (n+1)<=9 )
        buf[0][n+1] = (buf[0][n+1]=='O') ? '#' : 'O';
    buf[0][n] = (buf[0][n]=='O') ? '#' : 'O';
    buf[1][n] = (buf[1][n]=='O') ? '#' : 'O';

    solve(n+1, take+1);


    if( (n-1)>=0 )
        buf[0][n-1] = (buf[0][n-1]=='O') ? '#' : 'O';
    if( (n+1)<=9 )
        buf[0][n+1] = (buf[0][n+1]=='O') ? '#' : 'O';
    buf[0][n] = (buf[0][n]=='O') ? '#' : 'O';
    buf[1][n] = (buf[1][n]=='O') ? '#' : 'O';

    solve(n+1, take);

    return;
}

int main()
{
    char name[1000];

    while( cin>>name && strcmp(name, "end")!=0 )
    {
        count = 101;
        for(int i=0; i<10; i++)
            for(int j=0; j<10; j++)
                cin>>buf[i][j];

        solve(0, 0);

        cout<<name<<" "<<count<<endl;
    }
    return 0;
}
