#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, m;
long long box[100005];

bool check(long long time)
{
    long long tmp;
    int curr = 0;
    vector<long long> student(m, time);

    for( int i=0; i<n; i++ )
    {
        if( box[i]==0 )
            continue;

        tmp = 0;
        while( box[i]>=tmp )
        {
            tmp += student[curr] - ( i + 1 );
            curr++;
            if( curr>=m )
                break;
        }

        if( tmp>=box[i] )
        {
            curr--;
            student[curr] = tmp - box[i] + ( i + 1 );
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

long long bs(long long left, long long right)
{
    if( left==right )
        return left;

    unsigned long long mid = (left+right)/2;

    if( check(mid) )
        return bs(left, mid);
    else
        return bs(mid+1, right);
}

int main()
{
    while( scanf("%d %d", &n, &m)==2 )
    {
        for( int i=0; i<n; i++)
            scanf("%d", &box[i]);

        printf("%I64d\n", bs(1, 0xffffffffffff));
    }
    return 0;
}
