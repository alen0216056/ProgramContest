#include <iostream>

using namespace std;

int n, l, r, x, count;

void solve(int* ptr,int i, int min, int max, int sum)
{
    if( sum>r || i>n)
        return;

    if( sum>=l && sum<=r && (max-min)>=x && i==n)
        count++;

    solve(ptr, i+1, min, max, sum);

    sum += ptr[i];
    max = ptr[i]>max ? ptr[i] : max;
    min = ptr[i]<min ? ptr[i] : min;

    solve(ptr, i+1, min, max, sum);
}

int main()
{

    while( cin>>n && cin>>l && cin>>r && cin>>x )
    {
        int diff[n];
        for(int i=0; i<n; i++)
            cin>>diff[i];
        count = 0;

        solve(diff, 0, 1000000000, 0, 0);

        cout<<count<<endl;
    }
    return 0;
}
