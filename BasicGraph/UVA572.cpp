#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main()
{
    int n, m, x, y, ans, direction[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
    char c;
    pair<int, int> tmp, tmp2;

    while( cin>>m>>n && m!=0 )
    {
        ans = 0;
        bool oil[105][105] = {0}, connected[105][105] = {0};
        for(int i=1; i<=m; i++)
        {
            scanf("%c", &c);
            for(int j=1; j<=n; j++)
            {
                scanf("%c", &c);
                oil[i][j] = (c=='@');
            }
        }

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if( oil[i][j] && !connected[i][j] )
                {
                    ans++;

                    queue< pair<int, int> > q;
                    tmp.first = i;
                    tmp.second = j;
                    q.push(tmp);

                    while( !q.empty() )
                    {
                        tmp2 = q.front();
                        for(int k=0; k<8; k++)
                        {
                            x = tmp2.first + direction[k][0];
                            y = tmp2.second + direction[k][1];
                            if( oil[x][y] && !connected[x][y] )
                            {
                                tmp.first = x;
                                tmp.second = y;
                                connected[x][y] = 1;
                                q.push(tmp);
                            }
                        }
                        q.pop();
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
