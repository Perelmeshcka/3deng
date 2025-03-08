#include <stdbool.h>
#include <stdint.h>

void init();
bool is_open();
void close();
void events();
void tick();
void fill_background(uint8_t color[3]);
void draw_triangle(int pa[2], int pb[2], int pc[2], uint8_t color[3]);
