/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** game
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "proto.h"

int game_player_1(int pid_ennemi, char **map)
{
    char **map_ennemi = creat_tab();
    coord_t attack = {0, 0};
    int result = win_or_lose(map, map_ennemi);

    while (result == 0) {
        display(map, map_ennemi);
        my_putstr("\n");
        attack = get_input();
        modif_map_ennemi(map_ennemi, attack.x, attack.y, pid_ennemi);
        result = win_or_lose(map, map_ennemi);
        if (result) {
            return (display_result(result));
        }
        modif_map(map, pid_ennemi);
    }
    return (display_result(result));
}

int game_player_2(int pid_ennemi, char **map)
{
    char **map_ennemi = creat_tab();
    coord_t attack = {0, 0};
    int result = win_or_lose(map, map_ennemi);

    while (result == 0) {
        display(map, map_ennemi);
        modif_map(map, pid_ennemi);
        result = win_or_lose(map, map_ennemi);
        if (result) {
            return (display_result(result));
        }
        my_putstr("\n");
        attack = get_input();
        modif_map_ennemi(map_ennemi, attack.x, attack.y, pid_ennemi);
    }
    display_result(result);
    return (1);
}

int player_game(int nbr)
{
    if (nbr != -1) {
        return (2);
    }
    return (1);
}