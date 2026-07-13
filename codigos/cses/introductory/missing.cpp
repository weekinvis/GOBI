// enunciado: https://cses.fi/problemset/task/1083

// para essa questao, apenas a biblioteca padrao de input/output sera necessaria.
#include <iostream>
 
// para agilizar...
using namespace std;
 
// o tipo int pode ate suportar valores maiores que 2e5, entretanto, ao repetir somas para esse valor, pode ser que haja overflow no int.
typedef long long ll;
 
// nao eh necessario se preocupar com argc nem argv nesse exercicio.
int main() 
{
    ll n; cin >> n;
 
    // utilzo long long para resposta...
    ll soma = 0;
 
    // leio valores temporarios e somo eles...
    for(int i = 0; i < n - 1; i++)
    {
        int temp; cin >> temp;
        soma += temp;
    }
 
    // calculo o termo que falta.
    // a soma de todos os termos menos a soma que eu obti deve dar o termo que esta faltando.
    cout << (n * (n + 1)) / 2 - soma;
 
    // os juizes verificam se o codigo retornou sucesso
    return 0;
}