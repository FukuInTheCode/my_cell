#include "../../includes/my.h"

void my_cell_draw(sfRenderWindow * window, void *cell_ptr, void *params)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f ratio = {
        .x = window_size.x / SIZE,
        .y = window_size.y / SIZE,
    };
    sfCircleShape *cell = sfCircleShape_create
}