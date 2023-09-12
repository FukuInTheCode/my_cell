#include "../../includes/my.h"

static double normalize(double x)
{
    return (x > 0) - (x < 0);
}

static double control_coords(double x)
{
    if (x < 0)
        return 0;
    if (x > SIZE)
        return SIZE;
    return x;
}


static void check_new_atb(my_matrix_t *old_atb, uint32_t pop_size,\
                                        void *pop, my_matrix_t *new_atb)
{
    for (uint32_t i = 0; i < pop_size; ++i) {
        my_cell_t *cell_ptr = (my_cell_t *)((char *)pop + i * sizeof(my_cell_t));
        if (!my_matrix_equals(&(cell_ptr->atb), new_atb))
            continue;
        new_atb->arr[1][0] = old_atb->arr[1][0];
        new_atb->arr[0][0] = old_atb->arr[0][0];
    }
}

uint32_t my_cell_update(void *cell_ptr, void *pop,\
                                uint32_t pop_size, void *params)
{
    my_cell_t *cell = (my_cell_t *)cell_ptr;
    MAT_DECLA(datb);
    my_nn_predict(&(cell->brain), &(cell->atb), &datb);
    my_matrix_applyfunc_2(&datb, normalize);
    MAT_DECLA(new_atb);
    my_matrix_add(&new_atb, 2, &(cell->atb), &datb);
    my_matrix_applyfunc_2(&new_atb, control_coords);
    my_matrix_copy(&new_atb, &(cell->atb));
    my_matrix_free(2, &datb, &new_atb);
    return pop_size;
}
