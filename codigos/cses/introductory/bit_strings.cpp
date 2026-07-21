// enunciado: https://cses.fi/problemset/task/1617

#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
    ll n; cin >> n;
    ll modulo = 1e9 + 7;
    ll res = 1;

    for(ll i = 0; i < n; i++)
    {
        res = (res * 2) % modulo;
    }

    cout << res % modulo;
    
    return 0;

}