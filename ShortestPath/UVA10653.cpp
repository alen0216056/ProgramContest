#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

bool map[1000][1000];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

struct pos
{
    int x, y, dis;
};

int main()
{
    int col, row, start[2], end[2], n;

    while( scanf("%d%d", &row, &col) && !(row==0 && col==0) )
    {
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                map[i][j] = 1;

        scanf("%d", &n);
        while( n-- )
        {
            scanf("%d %d", &start[0], &start[1]);
            while( start[1]-- )
            {
                scanf("%d", &end[0]);
                map[start[0]][end[0]] = 0;
            }
        }

        scanf("%d %d %d %d", &start[0], &start[1], &end[0], &end[1]);

        map[start[0]][start[1]] = 0;
        queue<pos> q;
        pos tmp;
        tmp.x = start[0];
        tmp.y = start[1];
        tmp.dis = 0;
        q.push( tmp );
        while( !q.empty() )
        {
            int x = q.front().x, y = q.front().y, d = q.front().dis;

            if( x==end[0] && y==end[1] )
            {
                printf("%d\n", d);
                break;
            }
            for(int i=0; i<4; i++)
            {
                if( x+dir[i][0]>=0 && x+dir[i][0]<row && y+dir[i][1]>=0 && y+dir[i][1]<col && map[x+dir[i][0]][y+dir[i][1]] )
                {
                    tmp.x = x+dir[i][0];
                    tmp.y = y+dir[i][1];
                    tmp.dis = d+1;
                    q.push( tmp );
                    map[x+dir[i][0]][y+dir[i][1]] = 0;
                }
            }
            q.pop();
        }
    }

    return 0;
}
