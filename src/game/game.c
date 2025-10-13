// Arquivo: src/game.c

#include <stdio.h>
#include "game.h"

/**
 * Inicializa o tabuleiro com números de 1 a 9 para facilitar a escolha do jogador.
 * @param board O tabuleiro 3x3 a ser inicializado.
 */
void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    char cell_number = '1';
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = cell_number++;
        }
    }
}

/**
 * Desenha o tabuleiro no terminal.
 * @param board O tabuleiro 3x3 atual.
 */
void draw_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < BOARD_SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

/**
 * Verifica se o jogador atual venceu.
 * @param board O tabuleiro 3x3 atual.
 * @param player O caractere do jogador a ser verificado ('X' ou 'O').
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    // 1. Verificar Linhas e Colunas
    for (int i = 0; i < BOARD_SIZE; i++) {
        // Linhas (Horizontal)
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return 1;
        // Colunas (Vertical)
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return 1;
    }

    // 2. Verificar Diagonais
    // Diagonal principal (Esquerda Superior para Direita Inferior)
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return 1;

    // Diagonal secundária (Direita Superior para Esquerda Inferior)
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return 1;

    return 0; // Nenhuma vitória encontrada
}

/**
 * Verifica se o movimento é válido (se a célula está vazia e dentro do intervalo 1-9).
 * @param board O tabuleiro 3x3 atual.
 * @param move O número da célula escolhida pelo jogador (1 a 9).
 * @return 1 se o movimento for válido, 0 caso contrário.
 */
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int move) {
    if (move < 1 || move > NUM_CELLS) {
        return 0; // Fora do intervalo
    }
    
    // Converte o número do movimento (1-9) para coordenadas [linha][coluna]
    int row = (move - 1) / BOARD_SIZE;
    int col = (move - 1) % BOARD_SIZE;

    // Verifica se a célula ainda não foi marcada (contém um número)
    return (board[row][col] != 'X' && board[row][col] != 'O');
}

/**
 * Aplica o movimento ao tabuleiro.
 * @param board O tabuleiro 3x3.
 * @param move O número da célula escolhida (1 a 9).
 * @param player O caractere do jogador ('X' ou 'O').
 */
void make_move(char board[BOARD_SIZE][BOARD_SIZE], int move, char player) {
    // Converte o número do movimento (1-9) para coordenadas [linha][coluna]
    int row = (move - 1) / BOARD_SIZE;
    int col = (move - 1) % BOARD_SIZE;

    board[row][col] = player;
}
