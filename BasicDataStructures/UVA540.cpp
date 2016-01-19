#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int people[1000001];

int main()
{
    int n, m, i, count = 1;
    string s;

    while( cin>>n && n!=0 )
    {
        int team[1001] = {0}, t = 0;
        vector< queue<int> > v;

        while( n-- )
        {
            cin>>m;
            while( m-- )
            {
                cin>>i;
                people[i] = t;
            }
            t++;
        }

        cout<<"Scenario #"<<count<<endl;

        while( cin>>s && s!="STOP" )
        {
            if( s=="ENQUEUE" )
            {
                cin>>i;
                if( team[people[i]] && !v[team[people[i]]-1].empty() )
                {
                    v[team[people[i]]-1].push(i);
                }
                else
                {
                    queue<int> q;
                    q.push(i);
                    v.push_back(q);
                    team[people[i]] = v.size();
                }
            }
            else
            {
                for(i=0; i<v.size(); i++)
                {
                    if( !v[i].empty())
                    {
                        cout<<v[i].front()<<endl;
                        v[i].pop();
                        break;
                    }
                }
            }
        }
        cout<<endl;

        count++;
    }
    return 0;
}
