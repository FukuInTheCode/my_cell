#include "../../includes/my.h"

void my_cell_create(void *cell_ptr, void *params)
{
    my_cell_t *cell = (my_cell_t *)cell_ptr;
    uint32_t dims[] = {2, 3, 2};
    cell->brain.name = "brain";
    cell->brain.dims = dims;
    cell->brain.size = 3;
    my_nn_create(&(cell->brain));
    cell->atb.m = 0;
    cell->atb.n = 0;
    my_matrix_create(2, 1, 1, &(cell->atb));
    my_matrix_randint(0, SIZE, 1, &(cell->atb));
}
