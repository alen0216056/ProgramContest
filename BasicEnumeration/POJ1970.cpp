#include <iostream>
using namespace std;

int check(int* ptr, int x, int y, int flag)
{
    int i, buff_x, buff_y, color = *(ptr+(x*19+y));

    switch(flag)
    {
        case 0:
            buff_x = -1;
            buff_y = 1;
        break;
        case 1:
            buff_x = 0;
            buff_y = 1;
        break;
        case 2:
            buff_x = 1;
            buff_y = 1;
        break;
        case 3:
            buff_x = 1;
            buff_y = 0;
        break;
    }
    if( color==*(ptr + (x-buff_x)*19 + (y-buff_y)) )
        return 0;
    for(i=1; ; i++)
    {
        if( (x+i*buff_x)<0 || (x+i*buff_x)>18 || (y+i*buff_y)<0 || (y+i*buff_y)>18 || color!=*(ptr + ( (x+i*buff_x)*19 + (y+i*buff_y) )) )
            break;
    }

    if( i==5 )
        return color;
    else
        return 0;
}

int main()
{
    int n;

    cin>>n;
    while(n--)
    {
        int board[19][19];
        bool find = 0;

        for(int i=0; i<19; i++)
            for(int j=0; j<19; j++)
                cin>>board[i][j];

        for(int i=0; i<19 && !find; i++)
        {
            for(int j=0; j<19 && !find; j++)
            {
                if( board[i][j]==0 )
                    continue;

                for(int k=0; k<4; k++)
                {
                    int result = check(&board[0][0], i, j, k);
                    if( result>0 )
                    {
                        cout<<result<<endl;
                        cout<<i+1<<" "<<j+1<<endl;
                        find = 1;
                        break;
                    }
                }
            }

        }
        if( !find )
            cout<<"0"<<endl;
    }
    return 0;
}
