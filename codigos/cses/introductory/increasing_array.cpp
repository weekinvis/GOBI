// enunciado: https://cses.fi/problemset/task/1094
 
// para esse exercicio, precisaremos utilizar apenas iostream...
#include <iostream>
 
// para agilizar...
using namespace std;
 
// utilizaremos long long para as somas nao darem overflow no int.
typedef long long ll;// enunciado: https://cses.fi/problemset/result/17828745/
 
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
 
    while(par_inicio <= n)
    {
        cout << par_inicio << ' ';
        par_inicio += 2;
    }
 
    int impar_inicio = 1;
 
    while(impar_inicio <= n)
    {
        cout << impar_inicio << ' ';
        impar_inicio += 2;
    }
 
    return 0;
 
}

 
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