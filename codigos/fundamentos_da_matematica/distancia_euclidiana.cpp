// cout e cin
#include <iostream>

// struct com a implementacao dos dados dos pontos
struct ponto_s
{
    double x, y;
};

// funcao que calcula a distancia euclidiana
double calcula_distancia_euclidiana(ponto_s& p1, ponto_s& p2)
{
    // teorema de pitagoras
    return sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0));
}

// funcao principal
// nao eh necessario se preocupar com parametros da linha de comando e variaveis literais.
int main()
{
    // crio 2 pontos
    struct ponto_s p1, p2;

    // entrada de dados
    std::cin >> p1.x >> p1.y >> p2.x >> p2.y;

    
    // calculo e imprimo o resultado
    std::cout << "A distancia entre os pontos dados eh de: " \
    << calcula_distancia_euclidiana(p1, p2) << std::endl;

    // os juizes verificam se o codigo retornou sucesso
    return 0;
}