#ifndef PLAYER_H
#define PLAYER_H

#include <allegro.h>

#define MAX_CHARS 8

typedef struct PlayerDEF {
    BITMAP *Spr;
    char Name[50];
    int x, y;
    int State;
    int IndexAnim;
    int StartFrame;
    int TotalFrames;
    int QtdeFrames;
    int XAlign, YAlign;
    int slot[17];
    int bt_slot[17];
    int t_slot[17];
    int hp;
    // ... adicione outros campos conforme necessário
} PlayerDEF;

extern PlayerDEF P[3];

void player_init();
void player_update();
void player_shutdown();

void check_keys_P1();
void check_keys_P2();

void MovSlots_P1();
void MovSlots_P2();

void PLAYER_STATE(int Player, int State, int AnimIndex, int P1_QtdeFrames);

#endif // PLAYER_H