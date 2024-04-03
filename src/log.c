/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:42:56 by poss              #+#    #+#             */
/*   Updated: 2024/04/03 14:28:30 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"
#include <X11/keysym.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#define LOG_BUFFER_SIZE 128

void log_time(void)
{
    struct timeval curTime;
    gettimeofday(&curTime, NULL);
    int milli = curTime.tv_usec / 1000;

    char buffer[LOG_BUFFER_SIZE];
    strftime(buffer, LOG_BUFFER_SIZE, "%H:%M:%S", localtime(&curTime.tv_sec));

    char currentTime[LOG_BUFFER_SIZE + 4] = "";
    sprintf(currentTime, "%s:%03d", buffer, milli);
    printf("%s", currentTime);
}

void log_key_event(t_keycode keycode)
{
    log_time();
    printf("\tKey Event:\t");
    switch (keycode)
    {
        case XK_Escape:
            printf("Esc");
            break;
        case XK_p:
            printf("P");
            break;
        case XK_w:
            printf("W");
            break;
        case XK_a:
            printf("A");
            break;
        case XK_s:
            printf("S");
            break;
        case XK_d:
            printf("D");
            break;
        default:
            printf("%d", keycode);
    }
    printf("\n");
}
void log_loop_event(void)
{
    log_time();
    printf("\tLoop Event\n");
}
