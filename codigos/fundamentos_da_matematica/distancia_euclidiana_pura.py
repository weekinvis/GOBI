"""
Distância Euclidiana: distância em linha reta entre dois pontos.
Neste código, será utilizada apenas matemática.
"""

# Classe que representa um ponto
class Ponto:
    def __init__(self, x, y):
        self.x = x
        self.y = y

# Obtém as posições dos pontos a partir da entrada do usuário
ponto1 = Ponto(
    float(input()),
    float(input())
)

ponto2 = Ponto(
    float(input()),
    float(input())
)

"""
Obtém a distância euclidiana entre os dois pontos dados.
"""
def distancia_euclidiana(ponto1, ponto2):
    # Usa o Teorema de Pitágoras para encontrar a distância
    return ( ((ponto2.x - ponto1.x) ** 2) + ((ponto2.y - ponto1.y) ** 2) ) ** 0.5

# Calcula e imprime a distância euclidiana entre os pontos
print(f"A distância entre os pontos dados é: {distancia_euclidiana(ponto1, ponto2)}")


