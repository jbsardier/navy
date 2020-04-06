/*
** EPITECH PROJECT, 2020
** win
** File description:
** lose
*/

#include "proto.h"

int win_or_lose(char **map_p1, char **map_p2)
{
    if (win(map_p2) == 1) {
        return (1);
    } else if (lose(map_p1)  == 1) {
        return (2);
    } else {
        return (0);
    }
}

int win(char **map_p2)
{
    int x = 0;
    int y = 0;
    int count = 0;

    while (y < 8) {
        while (x < 8) {
            if (map_p2[y][x] == 'o') {
                count += 1;
            }
            x += 1;
        }
        x = 0;
        y += 1;
    }
    if (count == 14)
        return (1);
    return (0);
}

int lose(char **map_p1)
{
    int x = 0;
    int y = 0;

    while (y < 8) {
        while (x < 8) {
            if (map_p1[y][x] >= '2' && map_p1[y][x] <= '5') {
                return (0);
            }
            x += 1;
        }
        x = 0;
        y += 1;
    }
    return (1);
}