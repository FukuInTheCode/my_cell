#include "../../includes/my.h"

bool my_cell_is_select(void *cell_ptr, void *reward, uint32_t pop_size, void *params)
{
    my_cell_t *cell = (my_cell_t *)cell_ptr;
    double x = cell->atb.arr[0][0];
    double y = cell->atb.arr[1][0];
    if (x < SIZE / 3. * 2)
        return false;
    return true;
}
