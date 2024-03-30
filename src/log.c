/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:42:56 by poss              #+#    #+#             */
/*   Updated: 2024/03/30 16:43:33 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/time.h>
#include <stdio.h>

#define LOG_BUFFER_SIZE 128

void log_time(void)
{
    struct timeval curTime;
    gettimeofday(&curTime, NULL);
    int milli = curTime.tv_usec / 1000;

    char buffer [LOG_BUFFER_SIZE];
    strftime(buffer, LOG_BUFFER_SIZE, "%H:%M:%S", localtime(&curTime.tv_sec));

    char currentTime[LOG_BUFFER_SIZE + 4] = "";
    sprintf(currentTime, "%s:%03d", buffer, milli);
    printf("%s", currentTime);
}
