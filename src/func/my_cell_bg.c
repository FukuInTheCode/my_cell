#define MATRIX_INIT_STR
#include "../../includes/my.h"

void my_cell_draw_bg(sfRenderWindow *window, void *params)
{
    sfRenderWindow_clear(window, sfBlack);
    my_global_params_t *gps = (my_global_params_t *)params;
    char *str = init_str("gen n'", gps->gen_i);
    printf("%s\n", str);
    sfText *txt = sfText_create();
    sfText_setFont(txt, gps->font);
    sfText_setString(txt, str);
    sfText_setFillColor(txt, sfWhite);
    sfVector2f txt_pos = {0, 0};
    sfText_setPosition(txt, txt_pos);
    sfRenderWindow_drawText(window, txt, NULL);
    free(str);
    sfText_destroy(txt);

    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f ratio = {
        .x = window_size.x / SIZE,
        .y = window_size.y / SIZE
    };
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f rect_vec = {
        .x = ratio.x * SIZE / 3.,
        .y = window_size.y
    };
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(rect, 3);
    sfRectangleShape_setSize(rect, rect_vec);
    rect_vec.x += ratio.x * SIZE / 3.;
    rect_vec.y = 0;
    sfRectangleShape_setPosition(rect, rect_vec);
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    sfRectangleShape_destroy(rect);
}
