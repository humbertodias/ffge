#include "player.h"
#include <string.h>

PlayerDEF P[3];

// Inicializa os dados dos jogadores
void player_init() {
    for (int i = 1; i <= 2; i++) {
        P[i].Spr = create_bitmap(480, 480);
        clear_to_color(P[i].Spr, makecol(255,0,255));
        P[i].x = (i == 1) ? 150 : 350;
        P[i].y = 300;
        P[i].State = 0;
        P[i].IndexAnim = 0;
        P[i].StartFrame = 0;
        P[i].TotalFrames = 1;
        P[i].QtdeFrames = 1;
        P[i].XAlign = 0;
        P[i].YAlign = 0;
        strcpy(P[i].Name, (i == 1) ? "Player1" : "Player2");
        for (int j = 0; j < 17; j++) {
            P[i].slot[j] = 0;
            P[i].bt_slot[j] = 0;
            P[i].t_slot[j] = 0;
        }
    }
}

// Atualiza lógica dos jogadores por frame
void player_update() {
    check_keys_P1();
    check_keys_P2();
    MovSlots_P1();
    MovSlots_P2();
    // Exemplo de atualização de estado (poderia ser expandido)
    PLAYER_STATE(1, P[1].State, P[1].IndexAnim, P[1].QtdeFrames);
    PLAYER_STATE(2, P[2].State, P[2].IndexAnim, P[2].QtdeFrames);
}

// Libera recursos dos jogadores
void player_shutdown() {
    for (int i = 1; i <= 2; i++) {
        if (P[i].Spr) {
            destroy_bitmap(P[i].Spr);
            P[i].Spr = NULL;
        }
    }
}

// Checa teclas para Player 1 e atualiza slots de comando
void check_keys_P1() {
    // Exemplo de movimentação simples usando setas
    if (key[KEY_LEFT])  P[1].x -= 4;
    if (key[KEY_RIGHT]) P[1].x += 4;
    if (key[KEY_UP])    P[1].y -= 4;
    if (key[KEY_DOWN])  P[1].y += 4;

    // Exemplo de botão de ataque (Z)
    if (key[KEY_Z]) {
        P[1].State = 1; // Exemplo: estado de ataque
    }
}

// Checa teclas para Player 2 e atualiza slots de comando
void check_keys_P2() {
    // Exemplo de movimentação usando WASD
    if (key[KEY_A]) P[2].x -= 4;
    if (key[KEY_D]) P[2].x += 4;
    if (key[KEY_W]) P[2].y -= 4;
    if (key[KEY_S]) P[2].y += 4;

    // Exemplo de botão de ataque (L)
    if (key[KEY_L]) {
        P[2].State = 1; // Exemplo: estado de ataque
    }
}

// Gerencia slots de input, útil para comandos especiais (Player 1)
void MovSlots_P1() {
    // Exemplo: Armazena último movimento
    static int last_x = 0, last_y = 0;
    if (P[1].x != last_x || P[1].y != last_y) {
        // Desloca slots para trás e adiciona novo valor
        for (int i = 16; i > 0; i--) {
            P[1].slot[i] = P[1].slot[i-1];
        }
        P[1].slot[0] = (P[1].x << 8) | P[1].y;
        last_x = P[1].x;
        last_y = P[1].y;
    }
}

// Gerencia slots de input, útil para comandos especiais (Player 2)
void MovSlots_P2() {
    static int last_x = 0, last_y = 0;
    if (P[2].x != last_x || P[2].y != last_y) {
        for (int i = 16; i > 0; i--) {
            P[2].slot[i] = P[2].slot[i-1];
        }
        P[2].slot[0] = (P[2].x << 8) | P[2].y;
        last_x = P[2].x;
        last_y = P[2].y;
    }
}

// Atualiza o estado do jogador
void PLAYER_STATE(int Player, int State, int AnimIndex, int P1_QtdeFrames) {
    // Exemplo de lógica simples de estado
    if (State == 0) {
        // Estado parado
        // Poderia chamar animação de idle, etc.
    } else if (State == 1) {
        // Estado de ataque
        // Poderia chamar animação de ataque, etc.
        // Após realizar a ação, volta ao estado normal
        P[Player].State = 0;
    }
    // Outros estados podem ser tratados conforme necessidade
}