#include <stdlib.h>
#include <unistd.h>

static size_t ft_strlen(const char* s);

void die(const char* error_message)
{
    write(STDERR_FILENO, error_message, ft_strlen(error_message));
    exit(1);
}

static size_t ft_strlen(const char* s)
{
    size_t len = 0;

    if (!s)
        return 0;
    while (*s)
    {
        s++;
        len++;
    }
    return len;
}
