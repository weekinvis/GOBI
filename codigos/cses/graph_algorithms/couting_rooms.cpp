// enunciado: https://cses.fi/problemset/task/1192

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

const int maxn=1e3+40;

char rooms[maxn][maxn];
int ans=0;

int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(int x, int y)
{
    if(rooms[x][y] == '#') return;
    ans++;
    queue<pair<int, int>> que;

    // cout << "call: " << x <<' ' << y << endl;

    que.push({x, y});
    rooms[x][y] = '#';

    while(!que.empty())
    {
        auto c1 = que.front(); que.pop();

        int xa = c1.first,ya = c1.second;

        for(int i = 0; i < 4; i++)
        {
            int xr = xa + dx[i], yr = ya + dy[i]; 

            // cout << "trying: " << xr <<' ' << yr << endl;

            if(xr>=n||xr<0||yr>=m||yr<0) 
            {
                // cout << "continuing..." << endl;
                continue;
            }

            if(rooms[xr][yr] == '.')
            {
                que.push({xr,yr});
                rooms[xr][yr] = '#';
            } 
        }

    }

}

int main()
{
    cin>>n>>m;

    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>rooms[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(rooms[i][j] == '.')
                bfs(i,j);
        }
    }

    cout<<ans;

    return 0;
}