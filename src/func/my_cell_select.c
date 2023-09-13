#include "../../includes/my.h"

bool my_cell_is_select(void *cell_ptr, void *reward,\
                            uint32_t pop_size, void *params)
{
    my_cell_t *cell = (my_cell_t *)cell_ptr;
    double x = cell->atb.arr[0][0];
    if (x < SIZE / 5. * 4.)
        return false;
    return true;
}
