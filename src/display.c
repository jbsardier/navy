/*
** EPITECH PROJECT, 2020
** dis
** File description:
** play
*/

#include "proto.h"

int display(char **map_p1, char **map_p2)
{
    my_putstr("\n");
    my_putstr("my positions:");
    print_map(map_p1);
    my_putstr("\n");
    my_putstr("enemy's positions:");
    print_map(map_p2);
    return (0);
}

int display_result(int res)
{
    if (res == 1) {
        my_putstr("\nI won\n");
        return (1);
    } else if (res == 2) {
        my_putstr("\nEnemy won\n");
        return (2);
    }
    return (0);
}

int display_error(int ac)
{
    if (ac == 2) {
        my_putstr("USAGE\n");
        my_putstr("     ./navy [first_player_pid] navy_positions\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("     first_player_pid: only for the 2nd player. ");
        my_putstr("pid of the first player.\n");
        my_putstr("     navy_positions: file representing the ");
        my_putstr("positions of the ships.\n");
    } else {
        my_putstr_error("wrong number of argument\n");
    }
    return (0);
}