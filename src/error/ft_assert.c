#include "error.h"

void ft_assert(bool assertion, const char* message)
{
    if (assertion)
        return;
    die(message);
}
