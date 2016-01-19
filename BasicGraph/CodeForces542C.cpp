#include <iostream>
#include <cstdio>
using namespace std;

long long int max(long long int a, long long int b)
{
    return (a>b)? a: b;
}

long long int gcd(long long int a, long long int b)
{
    return (b%a==0)? a: gcd(b%a, a);
}

long long int lcm(long long int a, long long int b)
{
    long long int g = (a<b)? gcd(a, b): gcd(b, a);
    return a*b/g;
}

int main()
{
    int n, f[205], tmp;
    long long int count, loop[205], pre[205], before[205], ans[2] = {0, 1};

    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &f[i]);

    for(int i=1; i<=n; i++)
    {
        bool visited[205] = {0};

        tmp = i;
        count = 0;
        while( !visited[tmp] )
        {
            pre[tmp] = count;
            visited[tmp] = 1;
            tmp = f[tmp];
            count++;
        }
        before[i] = pre[tmp];
        loop[i] = count-pre[tmp];;
    }

    for(int i=1; i<=n; i++)
    {
        ans[0] = max(ans[0], before[i]);
        ans[1] = lcm(ans[1], loop[i]);
    }
    if( ans[0]%ans[1]!=0 )
        ans[0] = (ans[0]/ans[1]+1)*ans[1];

    ans[0] = max(ans[0], ans[1]);
    printf("%I64d\n", ans[0]);
    return 0;
}
