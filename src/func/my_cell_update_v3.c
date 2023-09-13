#define UPDATE_CELL_NATB_FUNC
#include "../../includes/my.h"

static void get_infos(my_matrix_t *infos, my_matrix_t *atb,\
                                void *pop, uint32_t pop_size)
{
    if (atb->arr[0][0] == 0)
        my_matrix_set(infos, 0, 0, 1);
    if (atb->arr[1][0] == 0)
        my_matrix_set(infos, 1, 0, 1);
    if (atb->arr[0][0] == SIZE)
        my_matrix_set(infos, 2, 0, 1);
    if (atb->arr[1][0] == SIZE)
        my_matrix_set(infos, 3, 0, 1);
}

uint32_t my_cell_update_v3(void *cell_ptr, void *pop,\
                                uint32_t pop_size, void *params)
{
    my_cell_t *cell = (my_cell_t *)cell_ptr;
    MAT_DECLA(infos);
    my_matrix_create(4, 1, 1, &infos);
    get_infos(&infos, &(cell->atb), pop, pop_size);
    MAT_DECLA(xs);
    my_matrix_concatrow(&xs, &(cell->atb), &infos);
    MAT_PRINT(xs);
    MAT_DECLA(pred);
    my_nn_predict(&(cell->brain), &xs, &pred);
    MAT_DECLA(datb);
    my_matrix_create(2, 1, 1, &datb);
    my_matrix_set(&datb, 0, 0, pred.arr[0][0]);
    my_matrix_set(&datb, 1, 0, pred.arr[1][0]);
    if (pred.arr[2][0] <= 0) {
        my_matrix_set(&datb, 0, 0, 0);
        my_matrix_set(&datb, 1, 0, 0);
    }
    my_matrix_applyfunc_2(&datb, normalize);
    MAT_DECLA(new_atb);
    my_matrix_add(&new_atb, 2, &(cell->atb), &datb);
    check_new_atb(&(cell->atb), pop_size, pop, &new_atb);
    my_matrix_copy(&new_atb, &(cell->atb));
    my_matrix_free(4, &datb, &new_atb, &xs, &infos);
    return pop_size;
}
