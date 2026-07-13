// enunciado: https://cses.fi/problemset/task/1068

// para essa questao, apenas a biblioteca padrao de input/output sera necessaria.
#include <iostream>
 
// para agilizar...
using namespace std;
 
// o tipo int pode ate suportar valores maiores que 10e6, entretanto, ao repetir o passo do caso impar para esse valor, pode ser que haja overflow no int.
typedef long long ll;
 
// nao eh necessario se preocupar com argc nem argv nesse exercicio.
int main() 
{
    // utilizo long long para a resposta...
    ll n; cin >> n;
 
    // imprimo n antes de comecar a mexer no seu valor...
    cout << n << ' ';
 
    // enquanto n for diferente de 1...
    while(n != 1)
    {
        // se n for impar entao multiplca por 3 e soma 1.
        // se for par entao divide n por 2.
        n = (n % 2) ? (n * 3 + 1) : (n/2);
        cout << n << ' ';
    } 
    
    // os juizes verificam se o codigo retornou sucesso
    return 0;
}