/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** get_input
*/

#include "my.h"
#include "proto.h"
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

coord_t get_input(void)
{
    char *str = malloc(sizeof(char) * 4096);
    size_t buflen = 0;
    coord_t result = {0, 0};

    my_putstr("attack: ");
    getline(&str, &buflen, stdin);
    result.x = coord_x(str);
    result.y = coord_y(str);
    if (result.x == -1 || result.y == -1) {
        my_putstr("wrong position\n");
        return (get_input());
    }
    my_putchar(result.x + 'A');
    my_putchar(result.y + '0');
    my_putstr(":");
    return (result);
}

int coord_x(char *str)
{
    int result = str[0] - 'A';

    if (result < 0 || result > 8) {
        result = -1;
    }
    return (result);
}

int coord_y(char *str)
{
    int result = str[1] - '0';
    if (result < 1 || result > 8) {
        result = -1;
    }
    return (result);
}
