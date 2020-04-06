/*
** EPITECH PROJECT, 2019
** Day02
** File description:
** my_put_nbr
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    unsigned int tmp = 0;
    if (nb < 0) {
        tmp = nb * -1;
        my_putchar('-');
    } else {
        tmp = nb;
    }
    if (tmp >= 10) {
        my_put_nbr(tmp / 10);
    }
    my_putchar((tmp % 10) + 48);
    return (0);
}
