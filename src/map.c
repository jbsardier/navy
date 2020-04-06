/*
** EPITECH PROJECT, 2020
** map
** File description:
** map
*/

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include "proto.h"
#include <stdlib.h>

char **fill_tab(char **map)
{
    int y = 0;
    int x = 0;

    while (y < 8) {
        while (x < 8) {
            map[y][x] = '.';
            x += 1;
        }
        map[y][x] = '\0';
        x = 0;
        y += 1;
    }
    return (map);
}

char **creat_tab(void)
{
    int i  = 0;
    char **tab = malloc(sizeof(char *) * 9);

    while (i < 9) {
        tab[i] = malloc(sizeof(char) * 9);
        i += 1;
    }
    tab[i - 1] = NULL;
    tab = fill_tab(tab);
    return (tab);
}

char **read_map(char *filepath)
{
    int i = 0;
    char *buf = malloc(sizeof(char) * 4096);
    int *boat = malloc(sizeof(int) * 4);
    char **tab = creat_tab();
    size_t buflen = 8;
    FILE *file;

    file = fopen(filepath, "r");
    if (file == NULL) {
        return (NULL);
    }
    while (i < 4) {
        getline(&buf, &buflen, file);
        if (!line_valid(boat, buf)) {
            return (NULL);
        }
        tab = fill_map(tab, buf);
        i += 1;
    }
    return (tab);
}

int modif_map_ennemi(char **map, int x, int y, int pid)
{
    int result = 0;
    send_sign(pid, x, 4);
    send_sign(pid, y, 4);
    result = recep_connection(4);

    if (result == 1) {
        map[y - 1][x] = 'o';
        my_putstr(" hit\n");
        return (1);
    } else {
        map[y - 1][x] = 'x';
        my_putstr(" missed\n");
        return (0);
    }
    return (0);
}

int modif_map(char **map, int pid)
{
    my_putstr("\nwaiting for enemy's attack...\n");
    int x = recep_connection(4);
    int y = recep_connection(4);

    usleep(100);
    my_putchar('A' + x);
    my_putchar('0' + y);
    my_putstr(": ");
    if (map[y - 1][x] != '.' && map[y - 1][x] != 'o' && map[y - 1][x] != 'x') {
        send_sign(pid, 1, 4);
        my_putstr("hit\n");
        map[y - 1][x] = 'o';
    } else {
        send_sign(pid, 2, 4);
        my_putstr("missed\n");
        map[y - 1][x] = 'x';
    }
    return (0);
}