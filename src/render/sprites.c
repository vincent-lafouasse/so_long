#include "sprites.h"
#include "render/image.h"

#define PLAYER_XPM "./assets/sprites/player.xpm"
#define COLLECTIBLE_XPM "./assets/sprites/collectible.xpm"
#define EXIT_XPM "./assets/sprites/exit.xpm"
#define FLOOR_XPM "./assets/sprites/floor.xpm"
#define WALL_XPM "./assets/sprites/wall.xpm"

t_sprites load_sprites(t_mlx mlx)
{
    t_sprites sprites;

    sprites.player = load_image_xpm(PLAYER_XPM, mlx);
    return sprites;
}
