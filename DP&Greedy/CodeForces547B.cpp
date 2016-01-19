#include <iostream>
#include <cstdio>
using namespace std;

int bears[200010] = {0}, ans[200010] = {0}, pos[200010] = {0}, l[200010] = {0}, r[200010] = {0};

int main()
{
    int n, len;

    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d", &bears[i]);

    l[0] = -1;
    pos[0] = -1;
    for(int i=1; i<n; i++)
    {
        int j = i-1;
        while( j>=0 && bears[j]>=bears[i] )
        {
            j = pos[j];
        }
        pos[i] = j;
        l[i] = j;
    }

    r[n-1] = n;
    pos[n-1] = n;
    for(int i=n-2; i>=0; i--)
    {
        int j = i+1;
        while( j<n && bears[j]>=bears[i] )
        {
            j = pos[j];
        }
        pos[i] = j;
        r[i] = j;
    }

    for(int i=0; i<n; i++)
    {
        len = r[i]-l[i]-1;
        ans[len] = max(bears[i], ans[len]);
    }

    for(int i=n; i>1; i--)
    {
        ans[i-1] = max(ans[i], ans[i-1]);
    }

    for(int i=1; i<=n; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}
