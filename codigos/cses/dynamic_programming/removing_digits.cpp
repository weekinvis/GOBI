// enunciado: https://cses.fi/problemset/task/1637
 
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
 
#define pb push_back
using namespace std;
 
const int inf = 2e6;
const int maxn = 2e6 + 9000;
 
typedef long long ll;
 
int dp[maxn];
 
vector<int> dgfy(int x)
{
    string s = to_string(x);
    vector<int> dig;
    dig.reserve(s.length());
 
    for(char c_ : s)
    {
        dig.pb(c_ - '0');
    }
 
    return dig;
}
 
int solve(int x)
{
    if(x == 0) return 1;
    if(x < 0) return inf;
    if(x >= maxn) return inf;
 
    // cout << "called:" << x << ' ' << dp[x] << endl;
 
    if(dp[x] != inf) return dp[x];
 
    for(int bar : dgfy(x))
    {
        // cout << "bar:" << bar << endl;
        dp[x] = min(dp[x], 1 + solve(x - bar));
    }
    return dp[x];
 
}
 
int main() 
{
    int n; cin >> n;
    for(int i = 0; i < maxn;i++)
    {
        dp[i]=inf;
    }
 
    for(int i = 1; i < n; i++)
    {
        solve(i);
    }
 
    cout << solve(n)-1<< endl;
 
    return 0;
}