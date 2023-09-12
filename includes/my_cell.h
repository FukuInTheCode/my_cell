#ifndef MY_CELL_H
#define MY_CELL_H

#include "my_neuralnetwork.h"
#include "my_evo.h"
#include "SFML/Graphics.h"

typedef struct {
    uint32_t gen_i;
    sfFont *font;
} my_global_params_t;

typedef struct {
    my_nn_t brain;
    my_matrix_t atb;
    sfColor color;
} my_cell_t;

#define CELL_DECLA(nvar) my_cell_t nvar = { \
        .brain = {.size = 0, .name = "brain"}, \
        .atb = {.m = 0, .n = 0, .name = "atb"} };

#define RADIUS 5

#define C_COLOR sfRed

#define SIZE 100.

void my_cell_create_v1(void *cell_ptr, void *params);
void my_cell_free(void *cell_ptr, void *params);
double my_cell_get_reward(void *cell_ptr, void *pop,\
                            uint32_t pop_size, void *params);
bool my_cell_is_select(void *cell_ptr, void *reward,\
                            uint32_t pop_size, void *params);
uint32_t my_cell_get_array(void *cell_ptr, double **arr, void *params);
void my_cell_from_array(void *cell_ptr, double *arr, void *params);
void my_cell_reset(void *cell_ptr, void *pop,\
                                    uint32_t pop_size, void *params);
uint32_t my_cell_update_v1(void *cell_ptr, void *pop,\
                                uint32_t pop_size, void *params);
void my_cell_draw(sfRenderWindow * window, void *cell_ptr, void *params);
void my_cell_draw_bg(sfRenderWindow *window, void *params);
void my_cell_update_params(void *pop, uint32_t pop_size, void *params_ptr);


#endif
