#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line/get_next_line.h"
#include "log.h"
#include "t_map.h"
#include "libft/string.h"

void remove_trailing_newline(char* string);
t_list* load_map_into_rev_list(const char* map_path)
{
    int fd = open(map_path, O_RDONLY);
    t_list* lines = NULL;
    t_list* current_node;
    char* line = get_next_line(fd);

    while (line)
    {
        remove_trailing_newline(line);
        current_node = ft_lstnew(line);
        ft_lstadd_front(&lines, current_node);
        line = get_next_line(fd);
    }

    close(fd);
    return lines;
}

void remove_trailing_newline(char* string)
{
    size_t len = ft_strlen(string);

    if (len == 0)
        return;

    if (string[len - 1] == '\n')
        string[len - 1] = '\0';
}

char** map_list_to_array(const t_list* map_list, t_dimension* return_dim)
{
    size_t height = ft_lstsize((t_list*)map_list);
    return_dim->h = height;
    return_dim->w = ft_strlen(map_list->content);
    char** map = malloc(height * sizeof(char*));

    while (map_list)
    {
        map[height - 1] = map_list->content;
        height--;
        map_list = map_list->next;
    }

    return map;
}

// `load_map` returns a map with NULL data if something failed
bool map_is_valid(t_map map)
{
    return map.data != NULL;
}

t_map invalid_map(void)
{
    t_map invalid;

    invalid.data = NULL;
    return invalid;
}

t_map load_map(const char* map_path)
{
    t_map map;
    t_list* map_lst = load_map_into_rev_list(map_path);
    log_str_lst(map_lst);

    map.data = (char**)1;

    return map;
}
