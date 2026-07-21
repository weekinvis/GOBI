#include <bits/stdc++.h>

using namespace std;
const int inf = 1e6 + 1;
const int maxn = 1e2 + 1;
 
vector<int> coins;
bool marker[inf]{};
int dp[inf];
 
int v, n;
 
int solve(int x)
{
	if(x == 0) return 0;
	if(0 > x) return inf;
 
	if(marker[x]) return dp[x];
 
	marker[x] = true;
 
	int bst = inf;
 
	for(int rs : coins) {
		if(x - rs >= 0)
		{
			bst = min(bst, solve(x - rs) + 1);
		}
 
	}
 
	dp[x] = bst;
 
	return bst;
 
}
 
int main(void)
{
	cin >> n >> v;
	coins.resize(n);
 
	for(int p = 0; p < n; p++)
		cin >> coins[p];
	
	int r = solve(v);
 
	if(r >= inf)
		cout << -1;
	else
		cout << r;
 
 
	return 0;
}