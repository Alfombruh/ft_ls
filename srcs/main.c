#include "libft.h"
#include "ft_ls.h"
#include "ft_printf.h"

static void freeList(t_list *list){
    t_list *temp = list;
    while(list){
        temp = list;
        list = list->next;
        free(temp);
    }
}

static void freeMemory(t_ls *ls){
    freeList(ls->directories);
}

// static int writeError(const char *msg){
//     write(2, msg, ft_strlen(msg));
//     return (1);
// }

int main(int argc, char **argv)
{
    t_ls ls;
    ft_bzero(&ls, sizeof(t_ls));
    if (parseArguments(argc, argv, &ls))
        return (1);
    printFlags(&ls);
    printDirectories(&ls);
    
    freeMemory(&ls);
    return (0);
}