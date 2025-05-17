#include "input.h"
#include <string.h>

// Instâncias globais dos controles de cada jogador
KeyState p1_left,  p1_right,  p1_up,  p1_down;
KeyState p1_bt1,   p1_bt2,    p1_bt3, p1_bt4, p1_bt5, p1_bt6, p1_select, p1_start;

KeyState p2_left,  p2_right,  p2_up,  p2_down;
KeyState p2_bt1,   p2_bt2,    p2_bt3, p2_bt4, p2_bt5, p2_bt6, p2_select, p2_start;

// Função auxiliar para atualizar o estado de uma tecla Allegro
static void update_key_state(KeyState *ks, int key_allegro) {
    int was_held = ks->held;
    ks->held     = key[key_allegro];
    ks->pressed  = (ks->held && !was_held);
    ks->released = (!ks->held && was_held);
    ks->status   = ks->held;
}

void input_init() {
    memset(&p1_left,   0, sizeof(KeyState));
    memset(&p1_right,  0, sizeof(KeyState));
    memset(&p1_up,     0, sizeof(KeyState));
    memset(&p1_down,   0, sizeof(KeyState));
    memset(&p1_bt1,    0, sizeof(KeyState));
    memset(&p1_bt2,    0, sizeof(KeyState));
    memset(&p1_bt3,    0, sizeof(KeyState));
    memset(&p1_bt4,    0, sizeof(KeyState));
    memset(&p1_bt5,    0, sizeof(KeyState));
    memset(&p1_bt6,    0, sizeof(KeyState));
    memset(&p1_select, 0, sizeof(KeyState));
    memset(&p1_start,  0, sizeof(KeyState));

    memset(&p2_left,   0, sizeof(KeyState));
    memset(&p2_right,  0, sizeof(KeyState));
    memset(&p2_up,     0, sizeof(KeyState));
    memset(&p2_down,   0, sizeof(KeyState));
    memset(&p2_bt1,    0, sizeof(KeyState));
    memset(&p2_bt2,    0, sizeof(KeyState));
    memset(&p2_bt3,    0, sizeof(KeyState));
    memset(&p2_bt4,    0, sizeof(KeyState));
    memset(&p2_bt5,    0, sizeof(KeyState));
    memset(&p2_bt6,    0, sizeof(KeyState));
    memset(&p2_select, 0, sizeof(KeyState));
    memset(&p2_start,  0, sizeof(KeyState));
}

void input_update() {
    // Player 1: setas e ZXCVBN, espaço e Enter (exemplo)
    update_key_state(&p1_left,   KEY_LEFT);
    update_key_state(&p1_right,  KEY_RIGHT);
    update_key_state(&p1_up,     KEY_UP);
    update_key_state(&p1_down,   KEY_DOWN);
    update_key_state(&p1_bt1,    KEY_Z);
    update_key_state(&p1_bt2,    KEY_X);
    update_key_state(&p1_bt3,    KEY_C);
    update_key_state(&p1_bt4,    KEY_V);
    update_key_state(&p1_bt5,    KEY_B);
    update_key_state(&p1_bt6,    KEY_N);
    update_key_state(&p1_select, KEY_SPACE);
    update_key_state(&p1_start,  KEY_ENTER);

    // Player 2: WASD e UIOJKL, Tab e Backspace (exemplo)
    update_key_state(&p2_left,   KEY_A);
    update_key_state(&p2_right,  KEY_D);
    update_key_state(&p2_up,     KEY_W);
    update_key_state(&p2_down,   KEY_S);
    update_key_state(&p2_bt1,    KEY_U);
    update_key_state(&p2_bt2,    KEY_I);
    update_key_state(&p2_bt3,    KEY_O);
    update_key_state(&p2_bt4,    KEY_J);
    update_key_state(&p2_bt5,    KEY_K);
    update_key_state(&p2_bt6,    KEY_L);
    update_key_state(&p2_select, KEY_TAB);
    update_key_state(&p2_start,  KEY_BACKSPACE);
}

void input_shutdown() {
    // Nenhum recurso a liberar nesse exemplo, mas a função existe para simetria
}