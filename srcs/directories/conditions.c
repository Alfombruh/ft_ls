#include "ft_ls.h"
#include "libft.h"
#include "ft_printf.h"
#include <sys/types.h>
#include <dirent.h>

int showDirectory(const t_ls *restrict ls, const char *restrict name, const int namelen){
    if ((namelen >= 1 && name[0] == '.') && ls->hidden_flag == false)
        return (1);
    return (0);
}

void newLine(const t_ls *restrict ls, const char *restrict path){
    if (ft_lstlast(ls->directories)->content != path && ft_lstsize(ls->directories) != 1)    
        write(1, "\n", 1);
    write(1, "\n", 1);
}

//Size might just not work and I might need to get rid of it
int writeSpace(const int index, const int size, struct dirent *dir_data){
    // ft_printf("namlen %d\n", (dir_data->d_namlen >= 1 && dir_data->d_name[0] == '.'));
    #ifdef __APPLE__
        if ((dir_data->d_namlen >= 1 && dir_data->d_name[0] == '.') || index != size)
            return (0);
    #elif __linux__
        if ((ft_strlen(dir_data->d_name) >= 1 && dir_data->d_name[0] == '.') || index != size)
            return (0);
    #endif
    return (1);
}

// int writeSpace(const int index, struct dirent *dir_data){
//     (void )index;
//     #ifdef __APPLE__
//         ft_printf("Im on apple\n");
//         if (dir_data->d_namlen >= 1 && dir_data->d_name[0] == '.')
//             return (0);
//     #elif __linux__
//         ft_printf("Im on linux\n");
//         if (ft_strlen(dir_data->d_name) >= 1 && dir_data->d_name[0] == '.')
//             return (0);
//     #endif
//     return (1);
// }