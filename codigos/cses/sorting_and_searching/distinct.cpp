// enunciado: https://cses.fi/problemset/task/1621

// para essa questao, utilizaremos a biblioteca de entrada e saida de dados e
// a estrutura de dado sets, que aceita apenas 1 elemento de cada valor
#include <iostream>
#include <set>

// para agilizar...
using namespace std;

int main() 
{
    // leio a quantidade de dados
    int n; cin >> n;

    // crio um set, uma estrutura de dados que nao aceita repeticoes
    set<int> estrutura_de_dados_set;

    // para n
    while(n--)
    {
        // leio o elemento atual
        int agora; cin >> agora;

        // insiro no set o elemento ´agora`, se o elemento for inserido ele nao existe no set,
        // caso contrario, ele eh ignorado.
        estrutura_de_dados_set.insert(agora);
    }

    // imprimo o tamanho dele, que sao os elementos distintos
    cout << estrutura_de_dados_set.size();

    // se chegou aqui, eh porque correu tudo bem
    return 0;
}