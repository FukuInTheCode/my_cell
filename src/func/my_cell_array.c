#define MATRIX_CHECK_ALLOC
#include "../../includes/my.h"

uint32_t my_cell_get_array(void *cell_ptr, double **arr, void *params)
{
    my_cell_t *cell = (my_cell_t *)cell_ptr;
    uint32_t arr_size = my_nn_get_n_params(&(cell->brain));
    *arr = calloc(arr_size, sizeof(double));
    my_nn_to_array(&(cell->brain), arr);
    cell->color = sfBlue;
    return arr_size;
}

void my_cell_from_array(void *cell_ptr, double *arr, void *params)
{
    my_cell_t *cell = (my_cell_t *)cell_ptr;
    cell->color = sfRed;
    my_nn_from_array(&(cell->brain), arr);
}
