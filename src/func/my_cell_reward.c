#include "../../includes/my.h"

double my_cell_get_reward(void *cell_ptr, void *pop,\
                            uint32_t pop_size, void *params)
{
    my_cell_t *cell = (my_cell_t *)cell_ptr;
    double x = cell->atb.arr[0][0];
    return SIZE - x;
}
