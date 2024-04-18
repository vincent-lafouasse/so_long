#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "error/error.h"
#include "get_next_line/get_next_line.h"
#include "libft/string.h"
#include "log.h"
#include "t_map_internals.h"

void remove_trailing_newline(char* string);
t_list* load_lines_in_lst(const char* map_path)
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

char** move_map_to_matrix(t_list** map_lst_ref, t_dimension size);

char** move_str_list_to_array(t_list** str_lst_ref);

void parse_map(t_map* map_return, t_list** map_list_ref)
{
    (void)map_return;
    (void)map_list_ref;
    return;
}

t_map load_raw_map_or_exit(const char* path)
{
    t_list* lines = load_lines_in_lst(path);
    log_str_lst(lines);
    if (lines == NULL)
        die("Failed to read lines from configuration file");
    t_map map;
    map.size = get_map_size(lines);
    if (map.size.h < 1 || map.size.w < 1)
        ft_lstclear(&lines, &free), die("map has invalid shape\n");

    return map;
}

t_map load_map_or_exit(const char* map_path)
{
    if (!str_ends_with(map_path, ".ber"))
        die("invalid map name");

    t_list* lines = load_lines_in_lst(map_path);
    log_str_lst(lines);

    t_map map;
    map.size = get_map_size(lines);  // move into parse map ?
    parse_map(&map, &lines);

    map.data = (char**)1;

    return map;
}
