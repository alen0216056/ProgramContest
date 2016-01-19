#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

bool map[100][100];
int horse_dir[8][2] = { {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };
int king_dir[8][2] = { {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0} };

struct pos
{
    int x, y, dis;
    pos(int _x, int _y, int _d):x(_x), y(_y), dis(_d){}
};

int main()
{
    int t, m, n, from[2], to[2], x, y, d;
    char buf[100];

    scanf("%d", &t);
    while( t-- )
    {
        scanf("%d%d", &m, &n);

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                map[i][j] = 1;

        for(int i=0; i<m; i++)
        {
            scanf("%s", &buf);
            for(int j=0; j<n; j++)
                if( buf[j]=='Z' )
                {
                    map[i][j] = 0;
                    for(int k=0; k<8; k++)
                        if( i+horse_dir[k][0]>=0 && i+horse_dir[k][0]<m && j+horse_dir[k][1]>=0 && j+horse_dir[k][1]<n )
                            map[i+horse_dir[k][0]][j+horse_dir[k][1]] = 0;
                }
                else if( buf[j]=='A' )
                {
                    from[0] = i;
                    from[1] = j;
                }
                else if( buf[j]=='B')
                {
                    to[0] = i;
                    to[1] = j;
                }
        }
        map[to[0]][to[1]] = 1;

        queue<pos> q;
        q.push( pos(from[0], from[1], 0) );
        while( !q.empty() )
        {
            x = q.front().x;
            y = q.front().y;
            d = q.front().dis;
            if( x==to[0] && y==to[1] )
            {
                printf("Minimal possible length of a trip is %d\n", d);
                break;
            }

            for(int i=0; i<8; i++)
                if( x+king_dir[i][0]>=0 && x+king_dir[i][0]<m && y+king_dir[i][1]>=0 && y+king_dir[i][1]<n && map[x+king_dir[i][0]][y+king_dir[i][1]] )
                {
                    q.push( pos(x+king_dir[i][0], y+king_dir[i][1], d+1) );
                    map[x+king_dir[i][0]][y+king_dir[i][1]] = 0;
                }

            q.pop();
        }
        if( x!=to[0] || y!=to[1] )
            printf("King Peter, you can't go now!\n");
    }
    return 0;
}
