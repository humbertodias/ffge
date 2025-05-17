#ifndef ENEMY_H
#define ENEMY_H

#include <allegro.h>

#define MAX_ENEMIES 4

typedef struct EnemyDEF {
    BITMAP *Spr;
    char Name[50];
    int x, y;
    int State;
    int IndexAnim;
    int StartFrame;
    int TotalFrames;
    int QtdeFrames;
    int XAlign, YAlign;
    int hp;
    // Adicione outros campos necessários para o seu jogo
} EnemyDEF;

extern EnemyDEF E[MAX_ENEMIES];

// Inicializa os inimigos
void enemy_init();

// Atualiza lógica dos inimigos por frame
void enemy_update();

// Libera recursos dos inimigos
void enemy_shutdown();

// Exemplo de função para controlar estado
void ENEMY_STATE(int enemy_id, int state, int anim_index, int qtde_frames);

#endif // ENEMY_H