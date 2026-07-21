// enunciado: https://cses.fi/problemset/task/1618

#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll ans = 0;

    int n; cin >> n;

    for(int i = 5; i <= n; i*=5)
    {
        ans += n/i;
    }

    cout << ans;
    return 0;
}