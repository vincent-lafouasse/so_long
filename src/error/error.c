#include "error.h"
#include <stdlib.h>
#include <unistd.h>
#include "libft/ft_io.h"

void die(const char* error_message)
{
    ft_putstr_fd("Error\n", STDERR_FILENO);
    ft_putendl_fd(error_message, STDERR_FILENO);
    exit(1);
}

void ft_assert(bool assertion, const char* message)
{
    if (assertion)
        return;
    die(message);
}
