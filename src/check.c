/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** check
*/

#include "my.h"
#include "proto.h"
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

int line_valid(int *boat, char *buf)
{
    int lenght = 0;
    int length_boat = 0;

    if (!check_str(buf)) {
        return (0);
    }
    lenght = buf[0] - '0';
    if (lenght > 1 && lenght < 6 && boat[lenght] == 0) {
        boat[lenght] = 1;
    } else {
        return (0);
    }
    length_boat = (buf[2] - buf[5]) + (buf[3] - buf[6]);
    if (length_boat + 1 == lenght || -length_boat + 1 == lenght) {
        return (1);
    }
    return (0);
}

int check_str(char *str)
{
    int i = 0;
    int test = 1;
    int count = 0;

    while (str[i] != '\0' && str[i] != '\n') {
        if (i == test && str[i] == ':') {
            test = test + 3;
        }
        if (i == test && str[i] != ':') {
            return (0);
        }
        ++count;
        ++i;
    }
    if (count != 7) {
        return (0);
    }
    return (1);
}