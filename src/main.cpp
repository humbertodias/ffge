// main.cpp
#include "engine.h"
#include "graphics.h"
#include "player.h"
#include "input.h"
#include "config.h"
#include "editor.h"
#include <allegro.h>

int main() {
    // Inicialização do Allegro e sistemas básicos
    set_uformat(U_UTF8); // Permite caracteres acentuados
    allegro_init();
    install_timer();
    install_keyboard();
    install_mouse();
    set_color_depth(32);

    // Inicialização da engine do jogo
    if (!engine_init()) {
        allegro_message("Erro ao inicializar a engine!");
        return 1;
    }

    // Carrega configurações e recursos
    config_load();
    graphics_init();
    player_init();
    input_init();
    editor_init();

    // Loop principal do jogo
    while (!engine_should_exit()) {
        engine_update();
        input_update();
        player_update();
        editor_update(); // Caso esteja no modo editor
        graphics_render();
    }

    // Finalizações
    editor_shutdown();
    player_shutdown();
    graphics_shutdown();
    engine_shutdown();

    return 0;
}
END_OF_MAIN();
