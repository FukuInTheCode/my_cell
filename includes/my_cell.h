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
void my_cell_create_v2(void *cell_ptr, void *params);
uint32_t my_cell_update_v2(void *cell_ptr, void *pop,\
                                uint32_t pop_size, void *params);
void my_cell_create_v3(void *cell_ptr, void *params);
uint32_t my_cell_update_v3(void *cell_ptr, void *pop,\
                                uint32_t pop_size, void *params);

#ifdef UPDATE_CELL_NATB_FUNC

static double normalize(double x)
{
    return (x > 0.5) - (x < 0.5);
}
static double normalize2(double x)
{
    return (x > 0) - (x < 0);
}

static double control_coords(double x)
{
    if (x < 0)
        return 0;
    if (x > SIZE)
        return SIZE;
    return x;
}

static void check_new_atb(my_matrix_t *old_atb, uint32_t pop_size,\
                                        void *pop, my_matrix_t *new_atb)
{
    my_matrix_applyfunc_2(new_atb, control_coords);
    for (uint32_t i = 0; i < pop_size; ++i) {
        my_cell_t *cell_ptr = (my_cell_t *)((char *)pop +\
                                        i * sizeof(my_cell_t));
        if (!my_matrix_equals(&(cell_ptr->atb), new_atb))
            continue;
        new_atb->arr[1][0] = old_atb->arr[1][0];
        new_atb->arr[0][0] = old_atb->arr[0][0];
    }
}
#endif



#endif
