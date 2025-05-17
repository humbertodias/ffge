#ifndef INPUT_H
#define INPUT_H

#include <allegro.h>

// Struct para armazenar o estado de uma tecla
typedef struct {
    int pressed;    // 1 se pressionou neste frame
    int held;       // 1 se está sendo segurada
    int released;   // 1 se soltou neste frame
    int status;     // estado geral (1 = pressionada, 0 = solta)
} KeyState;

// Estruturas de input para Player 1 e Player 2
extern KeyState p1_left, p1_right, p1_up, p1_down;
extern KeyState p1_bt1, p1_bt2, p1_bt3, p1_bt4, p1_bt5, p1_bt6, p1_select, p1_start;

extern KeyState p2_left, p2_right, p2_up, p2_down;
extern KeyState p2_bt1, p2_bt2, p2_bt3, p2_bt4, p2_bt5, p2_bt6, p2_select, p2_start;

// Inicializa o sistema de input
void input_init();

// Atualiza o estado dos inputs a cada frame
void input_update();

// Libera recursos, se necessário
void input_shutdown();

#endif // INPUT_H