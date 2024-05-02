#include "t_position_list.h"

#include <stdio.h>

static void log_poslst(const t_position_list* lst)
{
    while (lst)
    {
        printf("x%d\ty%d\n", lst->position.x, lst->position.y);
        lst = lst->next;
    }
}

int main()
{
    t_position_list* lst = poslst_new(position(3, 4));
    poslst_add_front(&lst, poslst_new(position(4, 5)));
    poslst_add_front(&lst, poslst_new(position(6, 9)));
    poslst_add_front(&lst, poslst_new(position(42, 9)));
    poslst_add_front(&lst, poslst_new(position(6, 9)));

    log_poslst(lst);
    printf("\nAfter\n");
    poslst_remove(&lst, position(6, 9));
    log_poslst(lst);
}
