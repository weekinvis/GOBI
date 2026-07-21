// enunciado: https://cses.fi/problemset/task/1092

#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    ll n; cin >> n;
 
    ll soma = (n * (n + 1)) / 2;
 
    vector<ll> vk;
    vk.reserve(10000);
 
    if(soma%2)
    {
        cout << "NO";
        return 0;
    }
 
    ll alvo = soma / 2;
 
    ll pace = n;
    while(alvo)
    {
        // if(pace < 0)
        // {
        //     cout << "NO";
        //     return 0;
        // }
        if(alvo - pace >= 0)
        {
            vk.push_back(pace);
            alvo -= pace;
        }
        pace--;
    }
 
    cout << "YES" << endl;
 
    cout << vk.size() << endl;
    
    for(ll vint : vk)
    {
        cout << vint << ' ';
    }
    cout<<endl;
 
    vector<ll>::iterator it = vk.begin();
    cout << n - vk.size() << endl;
    for(ll i = n; i >= 0; i--)
    {
        if(i != *it)
        {
            cout << i << ' ';
        }
        else
        {
            it++;
        }
    }
 
    return 0;
}