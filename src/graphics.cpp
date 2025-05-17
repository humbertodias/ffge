#include "graphics.h"
#include "player.h"
#include "enemy.h"

static BITMAP *buffer = NULL;
static int screen_width = 640;
static int screen_height = 480;

bool graphics_init() {
    set_color_depth(32);
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, screen_width, screen_height, 0, 0) != 0) {
        allegro_message("Erro ao inicializar o modo gráfico!");
        return false;
    }

    buffer = create_bitmap(screen_width, screen_height);
    if (!buffer) {
        allegro_message("Erro ao criar buffer gráfico!");
        return false;
    }
    return true;
}

void graphics_shutdown() {
    if (buffer) {
        destroy_bitmap(buffer);
        buffer = NULL;
    }
    set_gfx_mode(GFX_TEXT, 0, 0, 0, 0); // Volta ao modo texto
}

void graphics_render() {
    if (!buffer) return;

    clear_to_color(buffer, makecol(70, 70, 70)); // Fundo cinza escuro

    // Desenhar jogadores (assume P[1] e P[2] de player.h)
    for (int i = 1; i <= 2; i++) {
        draw_player(i, P[i].x, P[i].y, P[i].Spr);
    }

    // Desenhar inimigos (assume E[MAX_ENEMIES] de enemy.h)
    for (int i = 0; i < MAX_ENEMIES; i++) {
        draw_enemy(i, E[i].x, E[i].y, E[i].Spr);
    }

    // Exemplo de HUD (vida do Player 1)
    rect(buffer, 10, 10, 110, 30, makecol(255, 255, 255));
    rectfill(buffer, 11, 11, 11 + P[1].hp, 29, makecol(0, 255, 0));

    // Blita o buffer para a tela
    blit(buffer, screen, 0, 0, 0, 0, screen_width, screen_height);
}

void draw_player(int player_id, int x, int y, BITMAP *spr) {
    if (spr) {
        draw_sprite(buffer, spr, x, y);
    } else {
        // Caso não haja sprite, desenha um quadrado colorido
        rectfill(buffer, x, y, x+40, y+80, makecol(0, 0, 255));
    }
}

void draw_enemy(int enemy_id, int x, int y, BITMAP *spr) {
    if (spr) {
        draw_sprite(buffer, spr, x, y);
    } else {
        // Caso não haja sprite, desenha um quadrado vermelho
        rectfill(buffer, x, y, x+40, y+80, makecol(255, 0, 0));
    }
}