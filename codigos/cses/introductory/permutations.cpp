// enunciado: https://cses.fi/problemset/task/1070
 
// para essa questao, apenas a biblioteca de input/output padrao vai ser necessaria...
#include <iostream>
 
// para agilizar...
using namespace std;
 
// para essa questao, nao nos preocuparemos com argc nem argv
int main() 
{
    //leio a entrada
    int n; cin >> n;
    
    // para esses casos, o numero central sempre sera 1 unidade de distancia de qualquer outros dois numeros laterais...
    // nao eh possivel gerar uma solucao com esses numeros.
    if(n <= 3 && n != 1)
    {
        cout << "NO SOLUTION";
        // encerro a execucao do programa...
        return 0;
    }
 
    // um possivel raciocinio para solucionar essa questao eh que a diferenca entre dois numeros pares ou impares consecutivos eh sempre 2.
    // os numeros pares, nessa questao, nao comecam do 0, mas sim do 2.
    int par_inicio = 2;
 
    // enquanto o numero do inicio nao for igual ou maior no final
    while(par_inicio <= n)
    {
        // imprimo o numero par de agora
        cout << par_inicio << ' ';
        
        // somo 2 no par, que mantem o numero sendo par 
        par_inicio += 2;
    }
 
    int impar_inicio = 1;
 
    // enquanto o numero do inicio nao for igual ou maior no final
    while(impar_inicio <= n)
    {
        // imprimo o numero impar de agora
        cout << impar_inicio << ' ';

        // somo 2 no par, que mantem o numero sendo par
        impar_inicio += 2;
    }
 
    // os juizes verificam se o codigo retornou sucesso
    return 0;
}