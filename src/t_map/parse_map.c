#include "t_map_internals.h"

// here ?
#define VALID_CHARS "01CEP"

struct Charset
{
    char WALL;
    char EMPTY;
    char PLAYER;
    char COLLECTIBLE;
};

static bool map_is_enclosed(const t_map* map);
static bool map_contains_only_valid_char(const t_map* map);
static bool map_has_enough_tokens(const t_map* map);
static bool map_has_valid_path(const t_map* map);

void parse_map(t_map* map)
{
    (void)map;
}
