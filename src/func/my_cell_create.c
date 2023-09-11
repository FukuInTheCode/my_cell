#include "../../includes/my.h"

void my_cell_create(void *cell_ptr, void *params)
{
    my_cell_t *cell = (my_cell_t *)cell_ptr;
    uint32_t dims[] = {2, 3, 2};
    cell->brain.name = "brain";
    cell->brain.dims = dims;
    cell->brain.size = 3;
    my_nn_create(&(cell->brain));
    my_nn_print(&(cell->brain));
}
