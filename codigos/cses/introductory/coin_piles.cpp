// enunciado: https://cses.fi/problemset/task/1754

#include <iostream>

using namespace std;
typedef long long ll;

void solve(ll a,ll b)
{
    ll alf, bet;

    alf = 2*a-b;
    bet = 2*b-a;
    if(alf%3!=0 || bet%3!=0) 
    {
        cout << "NO";
        return;
    }
    alf/=3;
    bet/=3;
    ll t1 = 0, t2 = 0;

    t1 = alf*2+bet;
    t2 = alf+bet*2;

    if(t1!=a||t2!=b||alf<0||bet<0)
    {
        cout << "NO";
        return;
    }

    cout<<"YES";
}

int main() 
{
    int t; cin >> t;

    while(t--)
    {
        int a, b;
        cin>>a>>b;
        solve(a,b);
        cout<<endl;
    }
    
    return 0;
}