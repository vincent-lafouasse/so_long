#include <stdlib.h>
#include <unistd.h>
#include "libft/string.h"

void die(const char* error_message)
{
    write(STDERR_FILENO, error_message, ft_strlen(error_message));
    exit(1);
}
