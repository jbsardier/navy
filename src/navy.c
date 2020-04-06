/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy
*/
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "proto.h"

int navy(int nbr, char *path)
{
    ini_signal();
    int player = player_game(nbr);
    int pid = getpid();
    char **map = read_map(path);
    int pid_ennemi = 0;
    int res = 0;

    if (map == NULL) {
        return (84);
    }
    if (player == 1) {
        connection_player_one(&pid_ennemi, pid, nbr);
        res = game_player_1(pid_ennemi, map);
    } else {
        connection_player_two(&pid_ennemi, pid, nbr);
        res = game_player_2(pid_ennemi, map);
    }
    return (res - 1);
}

int connection_player_one(int *pid_ennemi, int pid, int nbr)
{
    my_putstr("my_pid: ");
    my_put_nbr(pid);
    my_putstr("\nwaiting for enemy connection...\n");
    *pid_ennemi = pid_game(1, nbr);
    usleep(100);
    kill(*pid_ennemi, SIGUSR1);
    my_putstr("\nenemy connected\n");
    return (0);
}

int connection_player_two(int *pid_ennemi, int pid, int nbr)
{
    my_putstr("my_pid: ");
    my_put_nbr(pid);
    *pid_ennemi = pid_game(2, nbr);
    send_sign(*pid_ennemi, pid, 24);
    pause();
    if (GLOBAL) {
        my_putstr("\nsuccessfully connected\n");
    }
    return (0);
}

int pid_game(int player, int nbr)
{
    if (player == 2) {
        return (nbr);
    } else {
        return (recep_connection(24));
    }
}

char *dec_to_bin(int nbr, int size)
{
    char *res = malloc(sizeof(char) * size + 1);

    size = size - 1;
    if (res == NULL) {
        return (NULL);
    }
    res[size] = '\0';
    while (size >= 0) {
        res[size] = (nbr % 2) + '0';
        nbr = nbr / 2;
        --size;
    }
    return (res);
}
