#include <iostream>
#include <algorithm>
using namespace std;

struct p
{
    int p1, p2;
};

int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7};
    p test[8]={ {1, 2}, {1, 3}, {1, 5}, {2, 3}, {2, 5}, {3, 4}, {3, 5}, {4, 5} };

    do{
        if( a[0]==0 || a[0]==1 || a[0]==2 )
        {
            int connect = test[a[0]].p2;
            int ans[9] = {1};
            int i;

            for(i=1; i<8; i++)
            {
                if( test[a[i]].p1==connect )
                {
                    ans[i] = connect;
                    connect = test[a[i]].p2;
                }
                else if( test[a[i]].p2==connect )
                {
                    ans[i] = connect;
                    connect = test[a[i]].p1;
                }
                else
                    break;
            }
            if( i==8 )
            {
                ans[8] = connect;
                for(int j=0; j<9; j++)
                    cout<<ans[j];
                cout<<endl;
            }
        }
        else
            break;
    }while( next_permutation(a, a+8) );

    return 0;
}
