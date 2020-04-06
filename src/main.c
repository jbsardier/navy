/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** main
*/

#include "proto.h"

int main(int ac, char **av)
{
    int nb1 = -1;

    if (ac == 3) {
        nb1 = my_getnbr(av[1]);
        return (navy(nb1, av[2]));
    } else if (ac == 2 && av[1][0] != '-' && av[1][1] != 'h') {
        return (navy(nb1, av[1]));
    } else {
        display_error(ac);
        return (84);
    }
    return (0);
}