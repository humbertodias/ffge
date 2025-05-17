#include "enemy.h"
#include <string.h>

EnemyDEF E[MAX_ENEMIES];

void enemy_init() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        E[i].Spr = create_bitmap(480, 480);
        clear_to_color(E[i].Spr, makecol(128, 0, 0));
        snprintf(E[i].Name, sizeof(E[i].Name), "Enemy%d", i+1);
        E[i].x = 200 + (i * 80);
        E[i].y = 300;
        E[i].State = 0;
        E[i].IndexAnim = 0;
        E[i].StartFrame = 0;
        E[i].TotalFrames = 1;
        E[i].QtdeFrames = 1;
        E[i].XAlign = 0;
        E[i].YAlign = 0;
        E[i].hp = 100;
        // Inicialize outros campos se necessário
    }
}

void enemy_update() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        // Exemplo simples: inimigo se move para a esquerda e volta
        if (E[i].State == 0) {
            E[i].x += (i % 2 == 0) ? 1 : -1;
            if (E[i].x > 400) E[i].State = 1;
            if (E[i].x < 100) E[i].State = 1;
        } else if (E[i].State == 1) {
            E[i].x += (i % 2 == 0) ? -1 : 1;
            if (E[i].x < 100) E[i].State = 0;
            if (E[i].x > 400) E[i].State = 0;
        }
        // Atualize animações ou lógica de IA aqui
        ENEMY_STATE(i, E[i].State, E[i].IndexAnim, E[i].QtdeFrames);
    }
}

void enemy_shutdown() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (E[i].Spr) {
            destroy_bitmap(E[i].Spr);
            E[i].Spr = NULL;
        }
    }
}

void ENEMY_STATE(int enemy_id, int state, int anim_index, int qtde_frames) {
    // Controle simples de estados para exemplo
    // Expanda com lógica de animação, ataque, etc., se quiser
    // Por exemplo:
    if (state == 0) {
        // Estado de patrulha
    } else if (state == 1) {
        // Estado de retorno
    }
    // Outros estados conforme sua necessidade
}