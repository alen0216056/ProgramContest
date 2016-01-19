#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

int in[30] = {0};
vector<int> graph[27];

void tp_sort()
{
    int i;
    char ans[27] ="";
    bool f = 1, visited[30] = {0};
    for(i=0; i<26 && f; i++)
    {
        f = 0;
        for(int j=0; j<26; j++)
        {
            if( in[j]==0 && !visited[j] )
            {
                for(int k=0; k<graph[j].size(); k++)
                    in[graph[j][k]]--;

                f = 1;
                visited[j] = 1;
                ans[i] = j + 'a';
                break;
            }
        }
    }
    ans[26] = '\0';
    if( i==26 )
        printf("%s\n", ans);
    else
        printf("Impossible\n");
}

int main()
{
    int n, len[2];
    char name[105][105];
    bool possible = 1, f = 0;

    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%s", &name[i]);

    for(int i=0; i<n-1 && possible; i++)
    {

        len[0] = strlen(name[i]);
        len[1] = strlen(name[i+1]);

        int temp = -1;
        for(int j=0; j<len[0] && j<len[1]; j++)
        {
            if(name[i][j]!=name[i+1][j])
            {
                temp = j;
                graph[name[i][j]-'a'].push_back(name[i+1][j]-'a');
                in[name[i+1][j]-'a']++;
                break;
            }
        }
        if( temp==-1 && len[0]>len[1])
            possible = 0;
    }

    if( possible )
        tp_sort();
    else
        printf("Impossible\n");

    return 0;
}
