#include "ft_ls.h"
#include "libft.h"
#include "ft_printf.h"
#include <sys/types.h>
#include <dirent.h>

// static int reverseListDirectory(const t_ls *restrict ls, const char *restrict path, const DIR *restrict directory){
    
// }

static int showDirectory(const t_ls *restrict ls, const char *restrict name, const int namelen){
    if ((namelen >= 1 && name[0] == '.') && ls->hidden_flag == false)
        return (1);
    return (0);
}

static int listDirectory(const t_ls *restrict ls, const char *restrict path){
    DIR *directory = opendir(path);
    if (!directory)
        return (directoryError(path));
    struct dirent *dir_data = readdir(directory);
    if (!dir_data)
        return (1);
    while (dir_data){
        if (!showDirectory(ls, dir_data->d_name, dir_data->d_namlen))
            ft_printf("%s", dir_data->d_name);
        dir_data = readdir(directory);
        if (!dir_data)
            break;
        write(1, " ", 1);
    }
    return (0);
}

static int reverseArguments(const t_ls *restrict ls){
    t_list *temp;
    int i = ft_lstsize(ls->directories);
    ft_printf("%d size\n", i);
    while(i != 0){
        int j = 0;
        temp = ls->directories;
        while (j++ != i - 1){
            temp = temp->next;
        }
        listDirectory(ls, temp->content);
        i--;
    }
    return (0);
}

int processArguments(const t_ls *restrict ls){
    t_list *temp = ls->directories;
    if (ft_lstsize(temp) == 0){
        listDirectory(ls, ".");
        return (0);
    }
    if (ls->reverse_flag){
        reverseArguments(ls);
        return (0);
    }
    while(temp){
        listDirectory(ls, temp->content);
        temp = temp->next;
    }
    return(0);
}