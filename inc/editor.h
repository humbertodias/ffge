#ifndef EDITOR_H
#define EDITOR_H

#include <allegro.h>

// Estados do editor
enum EditorMode {
    EDITOR_MODE_NONE = 0,
    EDITOR_MODE_STAGE,
    EDITOR_MODE_PLAYER,
    EDITOR_MODE_ENEMY
};

// Estrutura principal do editor
typedef struct {
    EditorMode mode;
    int selected_entity; // ID do jogador/inimigo/objeto selecionado
    int cursor_x, cursor_y;
    int is_active;
} EditorState;

// Estado global do editor
extern EditorState g_editor;

// Inicializa o editor (zera variáveis, carrega recursos)
void editor_init();

// Atualiza o editor (input, lógica)
void editor_update();

// Desenha o editor na tela (UI, seleções, etc)
void editor_render(BITMAP *target);

// Finaliza/libera recursos do editor
void editor_shutdown();

// Ativa/desativa o modo editor
void editor_toggle();

#endif // EDITOR_H