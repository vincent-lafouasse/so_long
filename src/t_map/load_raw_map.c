#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "error/error.h"
#include "geometry/geometry.h"
#include "get_next_line/get_next_line.h"
#include "libft/string.h"
#include "libft/t_list.h"
#include "log.h"
#include "t_map.h"
#include "t_map_internals.h"

static t_list* load_lines_in_lst(const char* map_path);
static t_map move_str_list_to_map(t_list** str_lst_ref);
static t_dimension get_map_size(const t_list* map_lst);

t_map load_raw_map_or_exit(const char* path)
{
    t_list* lines = load_lines_in_lst(path);
    ft_assert(lines != NULL, "Failed to read lines from configuration file");
    t_map map = move_str_list_to_map(&lines);
    ft_assert(map.data != NULL, "Failed to create char** map");

    return map;
}

t_map move_str_list_to_map(t_list** str_lst_ref)
{
    t_map map;
    t_list** head_ref = str_lst_ref;
    t_list* current = *head_ref;
    map.size = get_map_size(*head_ref);
    if (map.size.h < 2 || map.size.w < 2)
        ft_lstclear(head_ref, &free), die("map has invalid shape\n");

    map.data = malloc(sizeof(char*) * map.size.h);
    int row = map.size.h - 1;
    while (row >= 0 && current)
    {
        map.data[row] = (current)->content;
        row--;
        current = (current)->next;
    }

    if (row >= 0 || current != NULL)
        die("mismatched lines and rows");  // might need cleaning up

    ft_lstclear(head_ref, NULL);

    ft_assert(*head_ref == NULL, "map list was not freed properly.");
    printf("matrix\n");
    log_char_matrix((const char**)map.data, map.size);
    printf("size w %d\th %d\n", map.size.w, map.size.h);

    return map;
}

t_list* load_lines_in_lst(const char* map_path)
{
    int fd = open(map_path, O_RDONLY);
    t_list* lines = NULL;
    t_list* current_node;
    char* line = get_next_line(fd);

    while (line)
    {
        trim_trailing_newline(line);
        current_node = ft_lstnew(line);
        ft_lstadd_front(&lines, current_node);
        line = get_next_line(fd);
    }

    close(fd);
    log_str_lst(lines);
    return lines;
}

t_dimension get_map_size(const t_list* map_lst)
{
    t_dimension size;

    if (!map_lst)
        return (t_dimension){.w = 0, .h = 0};
    size.w = ft_strlen(map_lst->content);
    size.h = 1;
    map_lst = map_lst->next;
    while (map_lst)
    {
        if (ft_strlen(map_lst->content) != (size_t)size.w)
            return (t_dimension){.w = 0, .h = 0};
        size.h++;
        map_lst = map_lst->next;
    }

    return size;
}
