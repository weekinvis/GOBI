"""
Distância Euclidiana: distância em linha reta entre dois pontos.
Neste código, a função `math.dist()` (da biblioteca `math`) será utilizada,
uma vez que ela faz o cálculo da distância euclidiana.
"""
import math # math.dist

# Obtém as posições dos pontos a partir da entrada do usuário
# OBS.: precisa ser em vetor para a função `math.dist()` aceitar!
ponto1 = [
    float(input()),
    float(input())
]

ponto2 = [
    float(input()),
    float(input())
]

# Calcula e imprime a distância euclidiana entre os pontos
print(f"A distância entre os pontos dados é: {math.dist(ponto1, ponto2)}")


