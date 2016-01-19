#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    int p, a, b, c, d, n;

    while( cin>>p && cin>>a && cin>>b && cin>>c && cin>>d && cin>>n )
    {
        double max, ans=0;
        max = p * (sin(a+b) + cos(c+d) + 2);

        for(int i=2; i<=n; i++)
        {
            if( max- p * (sin(a*i+b) + cos(c*i+d) + 2) > ans)
                ans = max- p * (sin(a*i+b) + cos(c*i+d) + 2);
            if( p * (sin(a*i+b) + cos(c*i+d) + 2) > max)
                max = p * (sin(a*i+b) + cos(c*i+d) + 2);
        }
        cout<<fixed<<setprecision(7)<<ans<<endl;
    }
    return 0;
}
