// enunciado: https://cses.fi/problemset/task/1638

#include <iostream>

const int maxn = 1e3+400;
const int modulo = 1e9 + 7;

typedef long long ll;

char maze[maxn][maxn]{};
ll dp[maxn][maxn]{};
int n;

using namespace std;

ll solve(int x, int y)
{
    if(maze[x][y] == '*') return 0;
    if(x == (n - 1) && y == (n - 1)) return 1;
    if(x >= n || y >= n) return 0;

    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;

    return dp[x][y] = (solve(x + 1, y) + solve(x, y + 1)) % modulo;
    
}

int main()
{
    cin>>n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>maze[i][j];
            dp[i][j] = -1;
        }
    }

    cout<<solve(0,0);

    return 0;
}