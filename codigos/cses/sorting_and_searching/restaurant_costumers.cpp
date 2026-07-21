// enunciado: https://cses.fi/problemset/task/1619

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back

int main()
{
    vector<int> arrival, exit;
    int n; cin >> n;

    int c_ = 0;
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        int lw, rw;
        cin>>lw>>rw;
        arrival.pb(lw);
        exit.pb(rw);
    }

    sort(arrival.begin(), arrival.end());
    sort(exit.begin(), exit.end());

    for(int i = 0, j = 0; i < n;)
    {
        if(arrival[i] < exit[j])
        {
            c_++;
            i++;
        } else if(arrival[i] > exit[j])
        {
            c_--;
            j++;
        } else
        {
            i++;
            j++;
        }
        ans = max(c_, ans);
    }
    
    cout << ans;

    return 0;
}