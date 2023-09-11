#ifndef MY_CELL_H
#define MY_CELL_H

#include "my_neuralnetwork.h"
#include "SFML/Graphics.h"

typedef struct {
    my_nn_t brain;
    my_matrix_t atb;
    sfColor color;
} my_cell_t;

#define CELL_DECLA(nvar) my_cell_t nvar = { \
        .brain = {.size = 0, .name = "brain"}, \
        .atb = {.m = 0, .n = 0, .name = "atb"} };

#define RADIUS 5

#define C_COLOR sfRed

#define SIZE 512.

#endif