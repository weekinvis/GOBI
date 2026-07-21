// enunciado: https://cses.fi/problemset/task/2205

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void rev_fl(vector<string>& vks)
{
    for(int i = vks.size() - 1; i >= 0; i--)
    {
        string rs = vks[i];
        vks.push_back(rs);
    }
    for(int i = 0; i < vks.size() / 2; i++)
    {
        vks[i] = "0" + vks[i];
    }
    for(int i = vks.size() / 2; i < vks.size(); i++)
    {
        vks[i] = "1" + vks[i];
    }
}

int main()
{
    int n; cin >> n;
    vector<string> vks;
    string s_i = "0";

    vks.push_back(s_i);
    s_i = "1";
    vks.push_back(s_i);

    for(int i = 1; i < n; i++)
    {
        rev_fl(vks);
    }

    for(string strrs : vks)
    {
        cout << strrs << endl;
    }

    return 0;
}