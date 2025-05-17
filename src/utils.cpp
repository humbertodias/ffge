#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int rand_range(int min, int max) {
    if (min >= max) return min;
    return min + (rand() % (max - min + 1));
}

int clamp(int value, int min, int max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

unsigned long get_time_ms() {
    // Allegro: retorna o tempo desde o início em milissegundos
    return (unsigned long)(clock() * 1000 / CLOCKS_PER_SEC);
}

void utils_delay(unsigned int ms) {
    rest(ms);
}

void int_to_str(int value, char* buffer, int buffer_len) {
    if (!buffer || buffer_len < 2) return;
    snprintf(buffer, buffer_len, "%d", value);
}

void utils_log(const char *msg) {
    if (msg) {
        printf("[ffge] %s\n", msg);
        fflush(stdout);
    }
}