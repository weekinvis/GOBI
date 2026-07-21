// enunciado: https://cses.fi/problemset/task/1091

#include <iostream>
#include <set>

#define ub upper_bound

using namespace std;

int main()
{
    int n,m;cin>>n>>m;

    multiset<int> mst;

    for(int i = 0; i < n;i++)
    {
        int temp;cin>>temp;
        mst.insert(temp);
    }

    for(int i =0;i<m;i++)
    {
        int temp;cin>>temp;

        auto mstit = mst.ub(temp);

        if(mstit == mst.begin())
        {
            cout << "-1" << endl;
            continue;
        }
        --mstit;
        cout << *mstit << endl;
        mst.erase(mstit);

    }

    return 0;
}