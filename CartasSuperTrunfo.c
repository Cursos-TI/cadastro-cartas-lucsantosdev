#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

int main() {

  // Área para definição das variáveis para armazenar as propriedades das cidades
  #define ESTADOS 8
  #define CIDADES_POR_ESTADO 4

  typedef struct {
    char codigo[4]; // Ex: A01

    // Propriedades inseridas pelo usuário
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;

    // Propriedades calculadas
    float densidadePopulacional;
    float pibPerCapita;
  } Carta;

  Carta cartas[ESTADOS][CIDADES_POR_ESTADO];
    char estado;
    int cidade;

  printf("=== Super Trunfo - Tema: Países ===\n\n");

  // Área para entrada de dados
  for (int i = 0; i < ESTADOS; i++) {
    estado = 'A' + i;

    for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
      cidade = j + 1;

      // Gerando o código da carta
      sprintf(cartas[i][j].codigo, "%c%02d", estado, cidade);
      
      // Cadastrando a cidade
      printf("Cadastro da cidade %s\n", cartas[i][j].codigo);

      // Cadastro da população
      printf("População: ");
      scanf("%d", &cartas[i][j].populacao);

      // Cadastro da Área (em km²)
      printf("Área (km²): ");
      scanf("%f", &cartas[i][j].area);

      // Cadastro do PIB (em milhões)
      printf("PIB (em milhões): ");
      scanf("%f", &cartas[i][j].pib);

      // Cadastro do Número de Pontos Turísticos
      printf("Número de pontos turísticos: \n");
      scanf("%d", &cartas[i][j].pontosTuristicos);

      printf("------------------------------\n");

      // Cálculos de propriedades calculadas
      cartas[i][j].densidadePopulacional =
      cartas[i][j].populacao / cartas[i][j].area;

      cartas[i][j].pibPerCapita =
      cartas[i][j].pib / cartas[i][j].populacao;

    }             
  }

  // Área para exibição dos dados da cidade
  printf("\n=== Cartas Cadastradas ===\n\n");

  for (int i = 0; i < ESTADOS; i++) {
    for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
      printf("Código da Carta: %s\n", cartas[i][j].codigo);
      printf("População: %d\n", cartas[i][j].populacao);
      printf("Área: %.2f km²\n", cartas[i][j].area);
      printf("PIB: %.2f bilhões\n", cartas[i][j].pib);
      printf("Pontos Turísticos: %d\n", cartas[i][j].pontosTuristicos);
      printf("Densidade Populacional: %.2f hab/km²\n", cartas[i][j].densidadePopulacional);
      printf("PIB per Capita: %.6f\n", cartas[i][j].pibPerCapita);
      printf("------------------------------\n");
    }
  }

  return 0;
  
} 
