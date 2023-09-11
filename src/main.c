#include "../includes/my.h"

int main(int argc, char* argv[])
{
    srand(time(0));
    printf("HEllo\n");
    my_evo_t evo = {
        .pop_size = 100,
        .selected_size = 50,
        .max_tick_per_gen = 100,
        .mutation_chance = 0.3,
        .mutation_range = 1.,
        .agent_struct_size = sizeof(my_cell_t),
        .gen_skip = 0,
        .params = NULL,
        // .draw_agent = my_cell_draw,
        // .update_agent = my_cell_update,
        // .agent_is_select = my_cell_is_select,
        // .get_agent_reward = my_cell_get_reward,
        // .get_agent_array = my_cell_get_array,
        // .reset_agent = my_cell_reset,
        // .agent_from_array = my_cell_from_array,
        .create_agent = my_cell_create,
        .free_agent = my_cell_free
    };
    return 0;
}