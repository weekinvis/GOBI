// enunciado: https://cses.fi/problemset/task/1755

#include <iostream>
#include <string>
#include <deque>
using namespace std;

unsigned int arr[26]{};

int main()
{
    string s;
    deque<char> sol;
    bool impar;
    getline(cin, s);

    for(char c_ : s)
    {
        int pos = c_ - 'A';
        arr[pos]++;
    }

    impar = (s.length() % 2 == 1);

    for(int i = 0; i < 26; i++)
    {
        if(arr[i] % 2 == 1 && !impar)
        {
            cout << "NO SOLUTION";
            return 0;
        }
        else if(arr[i] % 2 == 1 && impar)
        {
            impar = false;
            sol.push_back((char)(i + 'A'));
        }
    }

    for(int i = 0; i < 26; i++)
    {
        
        for(int j = 0; j < arr[i] / 2; j++)
        {
            sol.push_back((char)(i+'A'));
            sol.push_front((char)(i+'A'));
        }
        
    }

    for(char c_ : sol)
    {
        cout << c_;
    }

    return 0;
}