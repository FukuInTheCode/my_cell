#define UPDATE_CELL_NATB_FUNC
#include "../../includes/my.h"

uint32_t my_cell_update_v1(void *cell_ptr, void *pop,\
                                uint32_t pop_size, void *params)
{
    my_cell_t *cell = (my_cell_t *)cell_ptr;
    MAT_DECLA(datb);
    my_nn_predict(&(cell->brain), &(cell->atb), &datb);
    my_matrix_applyfunc_2(&datb, normalize2);
    MAT_DECLA(new_atb);
    my_matrix_add(&new_atb, 2, &(cell->atb), &datb);
    check_new_atb(&(cell->atb), pop_size, pop, &new_atb);
    my_matrix_copy(&new_atb, &(cell->atb));
    my_matrix_free(2, &datb, &new_atb);
    return pop_size;
}
