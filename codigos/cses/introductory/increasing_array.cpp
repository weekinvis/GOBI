// enunciado: https://cses.fi/problemset/task/1094
 
// para essa questao, apenas a biblioteca de input/output padrao vai ser necessaria...
#include <iostream>
 
// para agilizar...
using namespace std;

// funcao que retorna um valor positivo ou nulo, transformando negativo em 0
int cap(int x) 
{
    return (x > 0) ? (x) : (0);
}
 
// nao precisamos nos preocupar com argc nem argv nesse momento...
int main() 
{
    // leio quantos elementos
    int n; cin >> n;

    // quanto precisara ser alterado
    ll passos = 0;

    // so precisamos do elemento atual e o proximo a comparar...
    int agora, proximo;
 
    // leio o primeior elemento
    cin >> agora;
 
    for(int i = 1; i < n; i++)
    {
        
        // a diferenca entre os dois
        int offset;
        
        // leio do 2o em diante
        cin >> proximo;

        // se o numero for negativo, retorna 0 (ou seja, nao precisa mudar nada)
        passos += offset = cap(agora - proximo);

        // atualizo o elemento para continuar no loop, ja incrementando o que precisa ser alterado
        agora = proximo + offset;
    }

    // imprimo a resposta
    cout << passos;
 
    // se chegou aqui eh porque correu tudo bem.
    // retorno sucesso.
    return 0;
}
