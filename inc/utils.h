#ifndef UTILS_H
#define UTILS_H

#include <allegro.h>

// Retorna um número aleatório entre min e max (inclusivo)
int rand_range(int min, int max);

// Limita um valor entre min e max
int clamp(int value, int min, int max);

// Retorna o tempo em milissegundos desde o início do programa
unsigned long get_time_ms();

// Delay customizado (em ms)
void utils_delay(unsigned int ms);

// Converte um valor inteiro para string (útil para HUD)
void int_to_str(int value, char* buffer, int buffer_len);

// Logging simples no console
void utils_log(const char *msg);

#endif // UTILS_H