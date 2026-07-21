#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 20;
const int modulo = 1e9 + 7;
 
ll dp[maxn]{};
 
ll solve(ll x)
{
    if(0 > x) return 0;
    if(x == 0) return 1;
 
    if(dp[x] != -1) return dp[x];
 
    dp[x] = 0;
    for(int p = 1; p <= 6; p++) {
        dp[x] = (dp[x] + solve(x - p)) % modulo;
    }
 
    return dp[x];
 
}
 
int main(void)
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
 
    cout << solve(n);
 
    return 0;
}