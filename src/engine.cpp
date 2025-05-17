#include "engine.h"
#include <allegro.h>

// Variável de controle para saída do jogo
static bool engine_exit = false;

// Timer global (opcional, útil para FPS ou lógica baseada em tempo)
volatile int engine_timer = 0;
void engine_timer_callback() { engine_timer++; }
END_OF_FUNCTION(engine_timer_callback);

// Função de callback para fechar a janela
void engine_close_callback() {
    engine_exit = true;
}
END_OF_FUNCTION(engine_close_callback);

// Inicializa os subsistemas principais da engine.
// Retorna true em caso de sucesso, false se houver falha crítica.
bool engine_init() {
    set_window_title("ffge - Free Fighting Game Engine");

    // Instala timer do Allegro
    if (install_timer() < 0) {
        allegro_message("Erro ao instalar timer!");
        return false;
    }

    // Instala timer customizado (1000 BPS = 1ms por incremento)
    LOCK_VARIABLE(engine_timer);
    LOCK_FUNCTION(engine_timer_callback);
    if (install_int_ex(engine_timer_callback, BPS_TO_TIMER(1000)) < 0) {
        allegro_message("Erro ao instalar engine timer!");
        return false;
    }

    // Instala teclado
    if (install_keyboard() < 0) {
        allegro_message("Erro ao instalar teclado!");
        return false;
    }

    // Instala mouse
    if (install_mouse() < 0) {
        allegro_message("Erro ao instalar mouse!");
        return false;
    }

    // Instala som (opcional)
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) < 0) {
        allegro_message("Erro ao instalar sistema de som!");
        // Não retorna falso, pois pode querer rodar sem som
    }

    // Seta callback para fechar a janela
    LOCK_FUNCTION(engine_close_callback);
    set_close_button_callback(engine_close_callback);

    // Outras inicializações podem ser feitas aqui...

    return true;
}

// Loop principal do jogo. Modularize chamando funções dos outros módulos dentro deste loop.
void engine_update() {
    // Loop principal: pode ser substituído por um loop mais elaborado
    while (!engine_should_exit()) {

        // Exemplo: Limpar tela, atualizar lógica, desenhar, etc.
        // clear_to_color(screen, makecol(0, 0, 0));

        // Aqui você chamaria:
        // input_update();
        // player_update();
        // game_update();
        // graphics_render();
        // etc.

        rest(1); // Pequena pausa para evitar uso total da CPU
    }
}

// Retorna true se o jogo deve encerrar (tecla ESC ou sinal de saída)
bool engine_should_exit() {
    return engine_exit || key[KEY_ESC];
}

// Finaliza subsistemas e libera recursos
void engine_shutdown() {
    // Remove timer customizado
    remove_int(engine_timer_callback);

    // Se necessário, outras limpezas aqui...
    // Por exemplo: destruir bitmaps, liberar áudio, etc.
}