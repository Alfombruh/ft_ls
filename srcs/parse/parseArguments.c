#include "libft.h"
#include "ft_ls.h"
#include <stdbool.h>

// decided to use a switch case since it uses binary search and its faster for lager groups
static int parseFlags(char *flags, t_ls *ls){
    int i = 0;
    if (ft_strlen(flags) == 1)
        return (1);
    while(flags[++i]){
        switch(flags[i]){
            case 'l':
                ls->list_flag = true;
                continue;
            case 'R':
                ls->recursive_flag = true;
                continue;
            case 'a':
                ls->hidden_flag = true;
                continue;
            case 'r':
                ls->reverse_flag = true;
                continue;
            case 't':
                ls->time_flag = true;
                continue;
            default:
                ft_putstr_fd(ERROR_USAGE ,2);
                return (1); 
        }
    }
    return (0);
}

static void parseDirectory(char *directory, t_ls *ls){
    ft_lstadd_back(&ls->directories, ft_lstnew(directory));
}

//Get rid of the variable bool flags in order to make it work like the ubuntu binary
static int checkArgument(char *argv, t_ls *ls, bool *flags){
    int i = -1;
    while (argv[++i]){
        if (argv[i] == '-' && *flags == true){
            *flags = true;
            if (parseFlags(&argv[i], ls))
                return (1);
            break;
        }
        parseDirectory(&argv[i], ls);
        *flags = false;
        break;
    }
    return (0);
}

int parseArguments(int argc, char **argv, t_ls *ls){
    if (argc == 1)
        return (0);
    int i = 0;
    bool flags = true;
    while (argv[++i]){
        if (checkArgument(argv[i], ls, &flags))
            return (1);
    }
    return (0);
}