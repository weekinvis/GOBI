// Bibliotecas necessarias
// scanf e printf
#include <stdio.h>
// sqrt e pow
#include <math.h>

// struct com a implementacao dos dados dos pontos
struct ponto_s {
    double x, y;
};

// funcao que calcula a distancia euclidiana
double calcula_distancia_euclidiana(struct ponto_s p1, struct ponto_s p2) {
    // teorema de pitagoras
    return sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0));
}

// funcao principal
// nao eh necessario se preocupar com parametros da linha de comando e variaveis literais.
int main() {
    // crio 2 pontos
    struct ponto_s p1, p2;

    // leio os dados p1 (x e y), p2 (x e y)
    (void)scanf("%lf%*c", &p1.x);
    (void)scanf("%lf%*c", &p1.y);
    (void)scanf("%lf%*c", &p2.x);
    (void)scanf("%lf%*c", &p2.y);

    // calculo e imprimo o resultado
    printf("A distancia entre os pontos dados eh: %lf\n", calcula_distancia_euclidiana(p1, p2));

    return 0;
}