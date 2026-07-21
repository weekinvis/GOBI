// enunciado: https://cses.fi/problemset/task/1071

// para essa questao, apenas a biblioteca com operacoes IO sera necessaria.
#include <iostream>
 
// para agilizar...
using namespace std;
typedef long long ll;
 
// 2 ints multiplicados podem dar overflow, por isso long long.
ll resolve(int y, int x)
{
    // salva o maior dos dois numeros
    int maior = max(y, x);

    // salva o quadrado do maior numero
    ll quadrado = maior;
    quadrado *= quadrado;
 
    // a logica se baseia em pensar que o numero esta entre o quadrado da maior coordenada e o quadrado do antecessor do maior numero
    // se o numero esta entre esses dois quadrados, precisamos obter qual eh o maior numero
    if(y > x)
    {
        if(maior % 2 == 1)
        {
            // o maior quadrado menos a coluna mais o deslocamento da linha mais uma unidade descartada do deslocamento da coluna
            return quadrado - maior - y + x + 1;
        } else 
        {
            // o maior quadrado menos o deslocamento da linha mais uma unidade descartada do deslocamento da linha
            return quadrado - x + 1;
        }
 
    } 
    else
    {
        if(maior % 2 == 1)
        {
            // o maior quadrado menos a linha mais o deslocamento da coluna mais uma unidade descartada do deslocamento da linha
            return quadrado - y + 1;
        } else
        {
            // o maior quadrado menos o deslocamento da coluna mais uma unidade descartada do deslocamento da coluna
            return quadrado - maior - x + y + 1;
        }
    }
 
}
 
int main() 
{
    // entrada de dados
    int y, x, t; cin >> t;
 
    // enquanto houver t.
    while(t--)
    {
        // le os dados
        cin >> y >> x;
    
        // imprime a solucao local
        cout << resolve(y, x) << endl;
    }
 
    // retorna 0
    return 0;
}