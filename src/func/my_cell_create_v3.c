#include "../../includes/my.h"

void my_cell_create_v3(void *cell_ptr, void *params)
{
    my_cell_t *cell = (my_cell_t *)cell_ptr;
    uint32_t dims[] = {6, 8, 8, 4, 3};
    cell->brain.name = "brain";
    cell->brain.dims = dims;
    cell->brain.size = 5;
    cell->brain.acti_type = base_type;
    cell->brain.funcs.af = my_nn_sin;
    cell->brain.funcs.grad_af = my_nn_sin_grad;
    my_nn_create(&(cell->brain));
    cell->atb.m = 0;
    cell->atb.n = 0;
    my_matrix_create(2, 1, 1, &(cell->atb));
    my_matrix_randint(0, SIZE, 1, &(cell->atb));
    cell->color = sfRed;
}
