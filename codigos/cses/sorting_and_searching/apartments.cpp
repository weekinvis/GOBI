// enunciado: https://cses.fi/problemset/task/1084

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back

int main()
{
    int n,m,k; cin>>n>>m>>k;
    vector<int> app, apa;

    int ans = 0;

    app.reserve(n);
    apa.reserve(m);

    for(int i = 0; i < n;i++)
    {
        int temp;
        cin >> temp;
        app.pb(temp);
    }

    for(int i = 0; i < m;i++)
    {
        int temp;
        cin >> temp;
        apa.pb(temp);
    }

    sort(app.begin(), app.end());
    sort(apa.begin(), apa.end());   

    auto appit = app.begin();
    auto apait = apa.begin();

    while(appit != app.end() && apait != apa.end())
    {
        if((*appit - k) <= *apait && (*appit + k) >= *apait)
        {
            ans++;
            appit++;
            apait++;
        } else if(appit != app.end() && (*appit - k) < *apait)
        {   
            appit++;
        } else
        {
            apait++;
        }
    }

    cout << ans;

    return 0;
}