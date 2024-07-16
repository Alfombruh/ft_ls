#include "ft_printf.h"
#include "ft_ls.h"
#include <sys/types.h>
#include <dirent.h>

static int showDir(const char *restrict path){
    ft_printf("path is ==> %s\n", path);
    DIR *directory = opendir(path);
    if  (directory == NULL)
        return (1);
    struct dirent *dir_data = readdir(directory);
    while ((dir_data = readdir(directory)))
    {
        if (dir_data == NULL)
            return (1);
        ft_printf("Directory name == %s\n", dir_data[0].d_name);
    }
    closedir(directory);
    return (0);
}

int printDirectory(const t_ls *restrict ls){
    if (ft_lstsize(ls->directories) == 0){
        if (showDir("."))
            return (1);
        return (0);
    }
    if (showDir(ls->directories->content))
        return (1);
    return (0);
}