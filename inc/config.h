#ifndef CONFIG_H
#define CONFIG_H

// =====================
// Configurações gerais
// =====================

// Título da janela do jogo
#define GAME_TITLE      "ffge - Free Fighting Game Engine"

// Resolução padrão
#define SCREEN_WIDTH    640
#define SCREEN_HEIGHT   480

// Profundidade de cor (bits)
#define COLOR_DEPTH     32

// FPS desejado
#define TARGET_FPS      60

// Número máximo de jogadores/inimigos
#define MAX_PLAYERS     2
#define MAX_ENEMIES     4

// Caminhos padrão de recursos (ajuste conforme necessário)
#define SPRITES_PATH    "assets/sprites/"
#define SOUNDS_PATH     "assets/sounds/"
#define MUSIC_PATH      "assets/music/"
#define FONTS_PATH      "assets/fonts/"

// =====================
// Teclas padrão (Allegro Keycodes)
// =====================
#define P1_KEY_LEFT     KEY_LEFT
#define P1_KEY_RIGHT    KEY_RIGHT
#define P1_KEY_UP       KEY_UP
#define P1_KEY_DOWN     KEY_DOWN
#define P1_KEY_BT1      KEY_Z
#define P1_KEY_BT2      KEY_X
#define P1_KEY_BT3      KEY_C
#define P1_KEY_BT4      KEY_V
#define P1_KEY_START    KEY_ENTER
#define P1_KEY_SELECT   KEY_SPACE

#define P2_KEY_LEFT     KEY_A
#define P2_KEY_RIGHT    KEY_D
#define P2_KEY_UP       KEY_W
#define P2_KEY_DOWN     KEY_S
#define P2_KEY_BT1      KEY_U
#define P2_KEY_BT2      KEY_I
#define P2_KEY_BT3      KEY_O
#define P2_KEY_BT4      KEY_J
#define P2_KEY_START    KEY_BACKSPACE
#define P2_KEY_SELECT   KEY_TAB

// Outras configurações podem ser adicionadas aqui...
void config_load();

#endif // CONFIG_H