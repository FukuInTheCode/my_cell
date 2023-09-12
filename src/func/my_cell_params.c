#include "../../includes/my.h"

void my_cell_update_params(void *pop, uint32_t pop_size, void *params_ptr)
{
    my_global_params_t *gps = (my_global_params_t *)params_ptr;
    ++(gps->gen_i);
}
