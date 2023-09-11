#include "../../includes/my.h"

double my_cell_get_reward(void *cell_ptr, void *pop,\
                            void *pop_size, void *params)
{
    my_cell_t *cell = (my_cell_t *)cell_ptr;
    double x = cell->atb.arr[0][0];
    double y = cell->atb.arr[1][0];
    return SIZE - x;
}
