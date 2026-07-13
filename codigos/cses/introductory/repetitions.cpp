// enunciado: https://cses.fi/problemset/task/1069
 
// para essa questao, string e iostream sera necessario...
#include <string>
#include <iostream>
 
// para agilizar
using namespace std;
 
int main() 
{
    // string para entrada...
    size_t qnt_max = 1;
    string entrada;
 
    // leio a entrada...
    getline(cin, entrada);
 
    // crio variaveis para o uso dos dados necessario
    for(size_t i = 0, repeticoes = 1; i < entrada.length() - 1; i++)
    {
        // caso haja uma repeticao, incremento um no valor, caso contrario, reseto para 1
        repeticoes = (entrada[i] == entrada[i + 1]) ? (repeticoes + 1) : 1;
        // max retorna o maior valor entre dois
        qnt_max = max(repeticoes, qnt_max);
    }
    // printa a quantidade maxima.
    cout << qnt_max;
 
    return 0;
}