/*
** EPITECH PROJECT, 2020
** header
** File description:
** mopolo
*/

#include "my.h"
#include "proto.h"

int print_something(int count)
{
    my_put_nbr(count);
    my_putchar('|');
    return (0);
}

char **fill_up(char **tab, char *pos)
{
    while (pos[3] <= pos[6]) {
        tab[pos[3] - '1'][pos[2] - 'A'] = pos[0];
        pos[3] += 1;
    }
    return (tab);
}

char **fill_line(char **tab, char *pos)
{
    while (pos[2] <= pos[5]) {
        tab[pos[3] - '1'][pos[2] - 'A'] = pos[0];
        pos[2] += 1;
    }
    return (tab);
}

char **fill_map(char **tab, char *pos)
{
    if (pos[2] == pos[5]) {
        tab = fill_up(tab, pos);
    } else {
        tab = fill_line(tab, pos);
    }
    return (tab);
}

int print_map(char **map)
{
    int x = 0;
    int y = 0;
    int i = 1;

    my_putstr("\n |A B C D E F G H\n-+---------------\n");
    while (y < 8) {
        my_putchar(i + 48);
        my_putchar('|');
        while (x < 8) {
            my_putchar(map[y][x]);
            my_putchar(' ');
            x += 1;
        }
        my_putchar('\n');
        i += 1;
        x = 0;
        y += 1;
    }
    return (0);
}