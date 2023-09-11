#include "../../includes/my.h"

static double normalize(double x)
{
    return (x > 0) - (x < 0);
}

static double control_coords(double x)
{
    return (int)x % SIZE;
}

uint32_t my_cell_update(void *cell_ptr, void *pop,\
                                uint32_t pop_size, void *params)
{
    my_cell_t *cell = (my_cell_t *)cell_ptr;
    MAT_DECLA(datb);
    my_nn_predict(&(cell->brain), &(cell->atb), &datb);
    my_matrix_applyfunc_2(&datb, normalize);
    MAT_DECLA(new_atb);
    my_matrix_add(&new_atb, 2, &(cell->atb), &datb);
    my_matrix_applyfunc_2(&new_atb, control_coords);
    my_matrix_free(2, &datb, &new_atb);
    return pop_size;
}
