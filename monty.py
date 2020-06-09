import random
import sys

iteracoes = int(sys.argv[1])
estrategia = str(sys.argv[2])

vitoria = 0
perdicao = 0

for i in range(iteracoes):
    premios = ["cabra", "cabra", "cabra"]
    print("----------JOGO", i+1, "----------")

    portaCarro = random.randint(0,2)
    portaJogador = random.randint(0,2)

    premios[portaCarro] = "carro"

    print("Voce escolheu a porta", portaJogador+1)

    for j in range(0,3):
        if (j != portaCarro and j != portaJogador):
            print("A porta", j+1, "tem uma cabra")
            portaCabra = j
            break;

    if estrategia == 't':
        if (portaJogador != 0 and portaCabra != 0):
            portaJogador = 0
        elif (portaJogador != 1 and portaCabra != 1):
            portaJogador = 1
        elif (portaJogador != 2 and portaCabra != 2):
            portaJogador = 2

        print("Voce troca para a porta", portaJogador+1)
    else :
        print("Voce continua na porta", portaJogador+1)


    if (premios[portaJogador] == "carro"):
        print("A sua porta tem um carro! PARABENS!")
        vitoria = vitoria + 1
    else :
        print("A sua porta tem uma cabra! Mais sorte na proxima")
        perdicao = perdicao + 1

    print(" ")

    print(premios[0], "|", premios[1], "|", premios[2])

print("---------\n")

print(vitoria, "vitorias -----> ", (vitoria * 100) / iteracoes, "%")
print(perdicao, "derrotas -----> ", (perdicao * 100) / iteracoes, "%")
