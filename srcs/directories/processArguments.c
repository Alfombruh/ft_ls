#include "ft_ls.h"
#include "libft.h"
#include "ft_printf.h"
#include <sys/types.h>
#include <dirent.h>

// static int reverseListDirectory(const t_ls *restrict ls, const char *restrict path, const DIR *restrict directory){
    
// }

// static int listDirectory(const t_ls *restrict ls, const char *restrict path){
//     DIR *directory = opendir(path);
//     int index = 0; //Just to avoid writting an extra " " at the end of the list
//     if (!directory)
//         return (directoryError(path));
//     struct dirent *dir_data = readdir(directory);
//     if (!dir_data)
//         return (1);
//     if (ft_lstsize(ls->directories) >= 2)
//         ft_printf("%s:\n", path);
//     while (dir_data){
//         index++;
//         #ifdef __APPLE__
//             if (!showDirectory(ls, dir_data->d_name, dir_data->d_namlen)){
//                 ft_printf("%s", dir_data->d_name);
//                 if (!writeSpace(index, directory->__dd_size, dir_data))
//                     write(1, "\t", 1);
//             }
//         #elif __linux__
//             if (!showDirectory(ls, dir_data->d_name, dir_data->d_namlen)){
//                 ft_printf("%s", dir_data->d_name);
//                 if (!writeSpace(index, directory->d_reclen, dir_data))
//                     write(1, "\t", 1);
//             }
//         #endif
//         dir_data = readdir(directory);
//         if (!dir_data){
//             newLine(ls, path);
//             break;
//         }
//     }
//     return (0);
// }

static int listDirectory(const t_ls *restrict ls, const char *restrict path){
    DIR *directory = opendir(path);
    int index = 0; //Just to avoid writting an extra " " at the end of the list
    if (!directory)
        return (directoryError(path));
    struct dirent *dir_data = readdir(directory);
    if (!dir_data)
        return (1);
    if (ft_lstsize(ls->directories) >= 2)
        ft_printf("%s:\n", path);
    while (dir_data){
        index++;
        #ifdef __APPLE__
            if (!showDirectory(ls, dir_data->d_name, dir_data->d_namlen)){
                ft_printf("%s", dir_data->d_name);
                if (!writeSpace(index, directory->__dd_size, dir_data))
                    write(1, "\t", 1);
            }
        #elif __linux__
            int number = 1; //random number given to just compile
            if (!showDirectory(ls, dir_data->d_name, ft_strlen(dir_data->d_name))){
                ft_printf("%s", dir_data->d_name);
                if (!writeSpace(index, number, dir_data))
                    write(1, "\t", 1);
            }
        #endif
        dir_data = readdir(directory);
        if (!dir_data){
            newLine(ls, path);
            break;
        }
    }
    closedir(directory);
    return (0);
}

static t_list *reverseArguments(const t_ls *restrict ls){
    t_list *new = NULL;
    t_list *temp = ls->directories;
    while(temp)
    {
        ft_lstadd_front(&new, ft_lstnew(temp->content));
        temp = temp->next;
    }
    return new;
}

int processArguments(t_ls *ls){
    t_list *temp = NULL;
    if (ls->time_flag)
        ;//rearange the files in time order
    if (ls->reverse_flag) // I really dont like if elses but the other option was a ternary. Maybe I could just write good code instead
        ls->directories = reverseArguments(ls);
    temp = ls->directories;
    if (ft_lstsize(temp) == 0){
        ft_lstadd_back(&ls->directories, ft_lstnew((void *)"."));
        listDirectory(ls, ".");
        return (0);
    }
    while(temp){
        if (listDirectory(ls, temp->content) == 1)
            ft_putstr_fd("error with directory\n", 2);
        temp = temp->next;
    }
    return(0);
}