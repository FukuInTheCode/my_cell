#include "../../includes/my.h"

void my_cell_draw(sfRenderWindow * window, void *cell_ptr, void *params)
{
    my_cell_t *cell = (my_cell_t *)cell_ptr;
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f ratio = {
        .x = (window_size.x) / SIZE / (1. + 1. / SIZE),
        .y = (window_size.y) / SIZE / (1. + 1. / SIZE)
    };
    sfCircleShape *pt = sfCircleShape_create();
    sfCircleShape_setFillColor(pt, cell->color);
    sfVector2f pos = {
        .x = cell->atb.arr[0][0] * ratio.x,
        .y = cell->atb.arr[1][0] * ratio.y,
    };
    sfCircleShape_setPosition(pt, pos);
    sfCircleShape_setRadius(pt, ratio.x * (1. + 1. / SIZE) / 2.);
    sfRenderWindow_drawCircleShape(window, pt, NULL);
    sfCircleShape_destroy(pt);
}