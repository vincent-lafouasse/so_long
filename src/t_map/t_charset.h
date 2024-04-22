#pragma once

#define DEFAULT_CHARSET "01CEP"

    typedef struct s_charset
{
    char EMPTY;
    char WALL;
    char COLLECTIBLE;
    char EXIT;
    char PLAYER;
} t_charset;

t_charset default_charset(void);
t_charset charset(const char* chars);
