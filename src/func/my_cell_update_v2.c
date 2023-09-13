#define UPDATE_CELL_NATB_FUNC
#include "../../includes/my.h"

uint32_t my_cell_update_v2(void *cell_ptr, void *pop,\
                                uint32_t pop_size, void *params)
{
    my_cell_t *cell = (my_cell_t *)cell_ptr;
    MAT_DECLA(pred);
    my_nn_predict(&(cell->brain), &(cell->atb), &pred);
    MAT_DECLA(datb);
    my_matrix_create(2, 1, 1, &datb);
    my_matrix_set(&datb, 0, 0, pred.arr[0][0]);
    my_matrix_set(&datb, 1, 0, pred.arr[1][0]);
    if (pred.arr[2][0] <= 0) {
        my_matrix_set(&datb, 0, 0, 0);
        my_matrix_set(&datb, 1, 0, 0);
    }
    my_matrix_applyfunc_2(&datb, normalize2);
    MAT_DECLA(new_atb);
    my_matrix_add(&new_atb, 2, &(cell->atb), &datb);
    check_new_atb(&(cell->atb), pop_size, pop, &new_atb);
    my_matrix_copy(&new_atb, &(cell->atb));
    my_matrix_free(2, &datb, &new_atb);
    return pop_size;
}
