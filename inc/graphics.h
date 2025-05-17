#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <allegro.h>

// Inicializa o sistema gráfico (resolução, buffer, etc)
bool graphics_init();

// Finaliza o sistema gráfico e libera recursos
void graphics_shutdown();

// Renderiza toda a cena: jogadores, inimigos, HUD, etc
void graphics_render();

// Função auxiliar: desenha um jogador na tela
void draw_player(int player_id, int x, int y, BITMAP *spr);

// Função auxiliar: desenha um inimigo na tela
void draw_enemy(int enemy_id, int x, int y, BITMAP *spr);

#endif // GRAPHICS_H