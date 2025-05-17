#include "editor.h"
#include "player.h"
#include "enemy.h"
#include <stdio.h>

EditorState g_editor;

void editor_init() {
    g_editor.mode = EDITOR_MODE_NONE;
    g_editor.selected_entity = -1;
    g_editor.cursor_x = 100;
    g_editor.cursor_y = 100;
    g_editor.is_active = 0;
}

void editor_toggle() {
    g_editor.is_active = !g_editor.is_active;
    if (g_editor.is_active) {
        g_editor.mode = EDITOR_MODE_STAGE;
        g_editor.selected_entity = -1;
    } else {
        g_editor.mode = EDITOR_MODE_NONE;
        g_editor.selected_entity = -1;
    }
}

// Exemplo básico de controle do editor (setas para mover, TAB troca modo, ENTER seleciona)
void editor_update() {
    if (!g_editor.is_active)
        return;

    // Troca de modo com TAB
    if (key[KEY_TAB]) {
        g_editor.mode = (EditorMode)(((int)g_editor.mode + 1) % 4);
        rest(150); // debounce
    }

    // Move cursor
    if (key[KEY_LEFT])  g_editor.cursor_x -= 4;
    if (key[KEY_RIGHT]) g_editor.cursor_x += 4;
    if (key[KEY_UP])    g_editor.cursor_y -= 4;
    if (key[KEY_DOWN])  g_editor.cursor_y += 4;

    // Seleciona entidade com ENTER
    if (key[KEY_ENTER]) {
        if (g_editor.mode == EDITOR_MODE_PLAYER)
            g_editor.selected_entity = 1; // Exemplo: seleciona Player 1
        else if (g_editor.mode == EDITOR_MODE_ENEMY)
            g_editor.selected_entity = 0; // Exemplo: seleciona Enemy 0
        else
            g_editor.selected_entity = -1;
        rest(150); // debounce
    }

    // Exemplo: arrasta entidade selecionada
    if (g_editor.selected_entity != -1) {
        if (g_editor.mode == EDITOR_MODE_PLAYER) {
            P[g_editor.selected_entity].x = g_editor.cursor_x;
            P[g_editor.selected_entity].y = g_editor.cursor_y;
        } else if (g_editor.mode == EDITOR_MODE_ENEMY) {
            E[g_editor.selected_entity].x = g_editor.cursor_x;
            E[g_editor.selected_entity].y = g_editor.cursor_y;
        }
        // Adicione lógica extra para salvar, deletar, etc.
    }
}

void editor_render(BITMAP *target) {
    if (!g_editor.is_active)
        return;

    // Desenha cursor
    circle(target, g_editor.cursor_x, g_editor.cursor_y, 8, makecol(255, 255, 0));

    // Mostra informações do editor
    textprintf_ex(target, font, 10, 10, makecol(255,255,0), -1, "EDITOR ATIVO [%s]",
        (g_editor.mode == EDITOR_MODE_STAGE) ? "STAGE" :
        (g_editor.mode == EDITOR_MODE_PLAYER) ? "PLAYER" :
        (g_editor.mode == EDITOR_MODE_ENEMY) ? "ENEMY" : "NONE");

    if (g_editor.selected_entity != -1) {
        textprintf_ex(target, font, 10, 25, makecol(255,255,255), -1,
            "Entidade selecionada: %d", g_editor.selected_entity);
    }
}

void editor_shutdown() {
    // Caso queira salvar algo ao sair do editor, faça aqui.
}