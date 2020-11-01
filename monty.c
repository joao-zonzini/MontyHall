#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define NUMERO_PORTAS 3

void printaPorta(int tipoPorta); void trocaCor(int n);

int main(int argc, char *argv[]) {

  //sem argumentos o programa nao continua
  argc > 2 ? : exit(0);

  long int iteracoes;
  long int vitoria = 0;
  long int perdicao = 0;
  int flagPremios[NUMERO_PORTAS];
  char estrategia;
  int portaJogador, portaCarro;
  int portasAbertas;

  srand(time(NULL));
  int seed = rand() % 100;

  iteracoes = atoi(argv[1]);
  estrategia = argv[2][0];

  clock_t begin = clock();

  for (long int i = 0; i < iteracoes; i++) {
    portasAbertas = 0;
    for (int j = 0; j < NUMERO_PORTAS; j++) {
      flagPremios[j] = 0;
    }

    printf("----------JOGO %ld----------\n", i+1);

    srandom(seed++);
    portaCarro = random() % NUMERO_PORTAS;
    srandom(seed * 3 + 1);
    portaJogador = random() % NUMERO_PORTAS;

    flagPremios[portaCarro] = 2;

    printf("Voce escolheu a porta %d\n", portaJogador+1);

    while (portasAbertas != NUMERO_PORTAS - 2) {

      for (int j = 0; j < NUMERO_PORTAS; j++) {
        if (j != portaCarro && j != portaJogador && flagPremios[j] != 1) {
          printf("A porta %d tem uma cabra\n", j+1);
          portasAbertas++;
          flagPremios[j] = 1;
          break;
        }
      }

      if (estrategia == 't') {
        for (int j = 0; j < NUMERO_PORTAS; j++) {
          if (portaJogador != j && flagPremios[j] != 1) {
            portaJogador = j;
            break;
          }
        }
        printf("Voce troca para a porta %d\n", portaJogador+1);
      } else {
        printf("Voce fica com a porta %d\n", portaJogador+1);
      }
    }


    if (flagPremios[portaJogador] == 2) {
      printf("\033[1;32m"); //verde
      printf("A sua porta tem um carro! PARABENS!\n");
      printf("\033[0m");    //reseta
      vitoria++;
    } else {
      printf("\033[1;31m"); //vermelho
      printf("A sua porta tem uma cabra! Mais sorte na proxima\n");
      printf("\033[0m");    //reseta
      perdicao++;
    }


    puts("");

    for (int j = 0; j < NUMERO_PORTAS; j++) {
      trocaCor(2);
      printaPorta(flagPremios[j]);
      trocaCor(0);
      printf(" | ");
    }

    puts("\n");

  }

  clock_t end = clock();

  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  puts("----------");

  printf("Tempo da iteracao: %.3f segundos\n", time_spent);
  trocaCor(1);
  printf("%ld vitorias -----> %ld%% \n", vitoria, (vitoria * 100) / iteracoes);
  trocaCor(2);
  printf("%ld derrotas -----> %ld%% \n", perdicao, (perdicao * 100) / iteracoes);
  trocaCor(0);
  printf("\n");

  return 0;
}

void printaPorta(int tipoPorta){
  switch (tipoPorta) {
    case 0:
      printf("cabra");
      break;

    case 1:
      printf("cabra");
      break;

    case 2:
      trocaCor(1);
      printf("carro");
      break;
  }
}

void trocaCor(int n) {
  switch (n) {
    case 0:
      printf("\033[0m");    //reseta
      break;
    case 1:
      printf("\033[1;32m"); //verde
      break;
    case 2:
      printf("\033[1;31m"); //vermelho
      break;
  }
}
