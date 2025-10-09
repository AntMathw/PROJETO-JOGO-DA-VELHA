#define JOGO_DA_VELHA

#include <stdbool.h>

#define tamanho_tabuleiro 3

extern char tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro];

void iniciar_tabuleiro();
void desenhar_tabuleiro();
bool verificar_vitória(char jogador);
bool verificar_empate();
void fazer_jogada(int jogada, char jogador);

#endif
