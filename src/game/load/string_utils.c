#include "libft/string.h"
#include "load_internals.h"

void trim_trailing_newline(char* s)
{
    size_t len = ft_strlen(s);

    if (len == 0)
        return;

    if (s[len - 1] == '\n')
        s[len - 1] = '\0';
}

bool str_ends_with(const char* s, const char* pattern)
{
    size_t offset;

    if (!s || !pattern)
        return false;
    if (ft_strlen(s) < ft_strlen(pattern))
        return false;
    offset = ft_strlen(s) - ft_strlen(pattern);
    return 0 == ft_strncmp(pattern, s + offset, ft_strlen(pattern));
}
