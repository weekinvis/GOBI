// enunciado: https://cses.fi/problemset/task/1636

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int modulo = 1e9 + 7;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> coin(n);
    for (int &c : coin) cin >> c;

    vector<ll> dp(x + 1, 0);
    dp[0] = 1;

    for (int c : coin) 
    {
        for (int i = c; i <= x; i++) 
        {
            dp[i] = (dp[i] + dp[i - c]) % modulo;
        }
    }

    cout << dp[x] << endl;

    return 0;
}