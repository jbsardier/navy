/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** signal
*/

#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "proto.h"

int recep_connection(int size)
{
    int result = 0;
    char *str = malloc(sizeof(char) * size + 1);

    if (str == NULL){
        return (-1);
    }
    str[size] = '\0';
    size = size - 1;
    while (size >= 0) {
        pause();
        str[size] = GLOBAL + '0';
        --size;
    }
    result = my_getnbr_base(str, "01");
    return (result);
}

void handler_sig1(int sig)
{
    (void) sig;
    GLOBAL = 1;
}

void handler_sig2(int sig)
{
    (void) sig;
    GLOBAL = 0;
}

void ini_signal(void)
{
    struct sigaction sa_sig1;
    struct sigaction sa_sig2;

    sa_sig1.sa_flags = SA_NODEFER;
    sa_sig2.sa_flags = SA_NODEFER;
    sigemptyset(&sa_sig1.sa_mask);
    sigemptyset(&sa_sig2.sa_mask);
    sa_sig1.sa_handler = handler_sig1;
    sa_sig2.sa_handler = handler_sig2;
    sigaction(SIGUSR1, &sa_sig1, NULL);
    sigaction(SIGUSR2, &sa_sig2, NULL);
}

int send_sign(int pid, int mes, int size)
{
    char *str = dec_to_bin(mes, size);

    size = size - 1;
    while (size >= 0) {
        if (str[size] == '1') {
            kill(pid, SIGUSR1);
        } else if (str[size] == '0') {
            kill(pid, SIGUSR2);
        }
        usleep(100);
        --size;
    }
    return (0);
}