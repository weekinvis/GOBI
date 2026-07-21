// enunciado: https://cses.fi/problemset/task/1158

#include <iostream>
using namespace std;
const int maxn = 1e3+30;
const int maxx = 1e5 + 30;

int dp[2][maxx]{};

int n, x;

int main()
{
    cin >> n >> x;
    int price[maxn]{}, pages[maxn]{};

    for(int i = 0; i < n;i++)
    {
        cin>>price[i];
    }
    
    for(int i = 0; i < n;i++)
    {
        cin>>pages[i];
    }

    for(int i = 0; i< n;i ++)
    {
        int line = (i+1)%2;

        for(int j = 1; j<=min(price[i]-1, x);j++)
        {
            dp[line][j] = dp[!line][j];
        }

        for(int j = price[i];j<=x;j++)
        {
            dp[line][j] = max(dp[!line][j], dp[!line][j-price[i]]+pages[i]);
        }
        // cout << "l: ";
        // for(int j = price[i]; j<=x;j++)
        // {
        //     cout<< dp[line][j] << ' ';
        // }
        // cout<<endl;
    }

    cout<<dp[!n][x];

    return 0;
}