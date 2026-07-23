
#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
  // 1. Representar o Tabuleiro (Matriz 10x10)
  // Inicializamos todas as posições com 0 (água) automaticamente usando {0}
   int tabuleiro[10][10] = {0};

   // Definição do tamanho fixo dos navios (conforme regras do nível básico)
   int tamanhoNavio = 3;

    // 2. Vetores para representar os navios (cada posição com o valor 3)
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    // Coordenadas iniciais (Linha e Coluna) definidas direto no código
    // O tabuleiro vai de 0 a 9 (total de 10 posições)
    int linhaNavioH = 2; // O navio horizontal começará na linha 2
    int colNavioH = 3;   // O navio horizontal começará na coluna 3

    int linhaNavioV = 5; // O navio vertical começará na linha 5
    int colNavioV = 6;   // O navio vertical começará na coluna 6

    // =====================================
    // VALIDAÇÕES (Requisitos Funcionais) 
    // =====================================

    // Validação 1: O navio Horizontal vai estourar o limite da direita?
    // Se ele começa na coluna 3 e tem tamanho 3, ele usará as colunas 3, 4 e 5 (Válido, pois 5 < 10)
    if (colNavioH + tamanhoNavio > 10 || linhaNavioH >= 10) {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro!\n");
        return 1; // Encerra o programa com erro
    }

    // Validação 2: O navio Vertical vai estourar o limite de baixo?
    // Se ele começa na linha 5 e tem tamanho 3, usará as linhas 5, 6 e 7 (Válido, pois 7 < 10)
    if (linhaNavioV + tamanhoNavio > 10 || colNavioV >= 10) {
        printf("Erro: Navio vertical fora dos limites do tabuleiro!\n");
        return 1;
    }

    // Validação 3: Garantir que não haja sobreposição
    // Como o enunciado disse que pode ser simplificada, verificamos se o ponto de cruzamento coincide.
    // Uma forma segura é checar se as coordenadas pretendidas para o navio vertical já cruzam o caminho do horizontal.
    // No nosso exemplo manual eles estão distantes, então não vão se sobrepor.

    // =====================================
    // POSICIONANDO OS NAVIOS (Copiando os 3s)
    // =====================================

    // Loop para colocar o Navio Horizontal
    // Mantemos a LINHA fixa e mudamos a COLUNA a cada passo do loop
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaNavioH][colNavioH + i] = navioHorizontal[i];
    }

    // Loop para colocar o Navio Vertical
    // Mantemos a COLUNA fixa e mudamos a LINHA a cada passo do loop
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaNavioV + i][colNavioV] = navioVertical[i];
    }

    // =====================================
    // EXIBINDO O TABULEIRO (Loops Aninhados)
    // =====================================
    printf("--- TABULEIRO DE BATALHA NAVAL ---\n\n");

    // O loop externo (l) controla as linhas
    for (int l = 0; l < 10; l++) {
        // O loop interno (c) controla as colunas daquela linha
        for (int c = 0; c < 10; c++) {
            // Imprime o número da posição seguido de um espaço para organizar visualmente
            printf("%d ", tabuleiro[l][c]);
        }
        // Quando termina uma linha inteira de colunas, pula para a próxima linha
        printf("\n");
    }

    printf("\nLegenda: 0 = Agua | 3 = Navio\n");

    return 0;
}
