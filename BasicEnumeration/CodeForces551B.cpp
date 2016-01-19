#include <iostream>
#include <string>
using namespace std;

int compute(int* ptr1, int* ptr2)
{
    int ans = 10000;

    for(int i=0; i<26; i++)
    {
        if( ptr2[i]!=0 && ans>ptr1[i]/ptr2[i] )
            ans = ptr1[i]/ptr2[i];
    }
    return ans;
}

bool check(int* ptr1, int* ptr2, int* ptr3, int b, int c)
{
    for(int i=0; i<26; i++)
    {
        if( ptr1[i]<(ptr2[i]*b + ptr3[i]*c) )
            return 0;
    }
    return 1;
}

int main()
{
    string a, b, c;

    while( cin>>a && cin>>b && cin>>c )
    {
        int max[3], b_max, c_max;
        int a_count[26] = {0}, b_count[26] = {0}, c_count[26] = {0};

        for(int i=0; i<a.length(); i++)
            a_count[a[i]-'a']++;
        for(int i=0; i<b.length(); i++)
            b_count[b[i]-'a']++;
        for(int i=0; i<c.length(); i++)
            c_count[c[i]-'a']++;

        b_max = compute(a_count, b_count);
        c_max = compute(a_count, c_count);

        if( b_max>=c_max )
        {
            max[0] = b_max;
            max[1] = b_max;
            max[2] = 0;

            for(int i=b_max; i>=1; i--)
            {
                for(int j=1; j<=c_max; j++)
                {
                    if( max[0]<(i+j) )
                    {
                        if( check(a_count, b_count, c_count, i, j) )
                        {
                            max[0] = i+j;
                            max[1] = i;
                            max[2] = j;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }

        }
        else
        {
            max[0] = c_max;
            max[1] = 0;
            max[2] = c_max;

            for(int i=c_max; i>=1; i--)
            {
                for(int j=1; j<=b_max; j++)
                {
                    if( max[0]<(i+j) )
                    {
                        if( check(a_count, b_count, c_count, j, i) )
                        {
                            max[0] = i+j;
                            max[1] = j;
                            max[2] = i;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }


        for(int i=0; i<max[1]; i++)
            cout<<b;
        for(int i=0; i<max[2]; i++)
            cout<<c;
        for(int i=0; i<26; i++)
            for(int j=0; j<(a_count[i]-max[1]*b_count[i]-max[2]*c_count[i]); j++)
                cout<<char(i+'a');
        cout<<endl;
    }
    return 0;
}
