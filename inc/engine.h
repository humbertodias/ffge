#ifndef ENGINE_H
#define ENGINE_H

// Inicializa subsistemas principais da engine. Retorna true se sucesso.
bool engine_init();

// Função que executa o loop principal do jogo.
void engine_update();

// Checa se o jogo deve encerrar.
bool engine_should_exit();

// Finaliza subsistemas e libera recursos.
void engine_shutdown();

#endif // ENGINE_H