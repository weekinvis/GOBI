#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll modulo = 1e9 + 7;
const int maxn = 1e6 + 20;
 
int n;
ll value;
 
int coins[maxn];
ll dp[maxn];
 
ll solve(ll x)
{
    if(x == 0) return 1;
    if(0 > x) return 0;
 
    if(dp[x] != -1) return dp[x];
 
    dp[x] = 0;
 
    for(int p = 1; p <= n; p++) {
        dp[x] = (dp[x] + solve(x - coins[p])) % modulo;
    }
    return dp[x];
 
}
 
int main(void)
{
    cin >> n >> value;
    memset(dp, -1, sizeof(dp));
 
    for(int p = 1; p <= n; p++)
    {
        cin >> coins[p];
    }
 
    cout << solve(value) << endl;
 
    return 0;
}