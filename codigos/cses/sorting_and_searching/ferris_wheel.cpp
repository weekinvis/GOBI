// enunciado: https://cses.fi/problemset/task/1090

#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back

using namespace std;

int main()
{  
    int n, w; cin >> n >> w;

    vector<int> child;

    child.reserve(n);

    for(int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        child.pb(temp);
    }

    sort(child.begin(), child.end());

    for(int i = 0, j = child.size() - 1; i < j;)
    {
        if(child[i] + child[j] <= w)
        {
            n--;
            i++;
            j--;
        } else
        {
            j--;
        }
    }

    cout << n;

    return 0;
}