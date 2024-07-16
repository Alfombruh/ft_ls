#include "ft_ls.h"
#include "libft.h"
#include "ft_printf.h"
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

int directoryError(const char *restrict name){
    ft_putstr_fd("ls: ",2);
    ft_putstr_fd((char *)name, 2);
    switch errno{
        case EACCES:
            ft_putstr_fd(": No permission to access this file or directory\n", 2);
            return (1);
        case EBADF:
            ft_putstr_fd(": Bad fd\n", 2);
            return (1);
        case EMFILE:
            ft_putstr_fd(": Per-process limit on the number of open file descriptors has been reached\n", 2);
            return (1);
        case ENFILE:
            ft_putstr_fd(": system-wide limit on the total number of open files has been reached\n", 2);
            return (1);
        case ENOENT:
            ft_putstr_fd(": No such file or directory\n", 2);
            return (1);
        case ENOMEM:
            ft_putstr_fd(": Insufficient memory\n", 2);
            return (1);
        case ENOTDIR:
            ft_putstr_fd(": Not a Directory\n", 2);
            return (1);
        default:
            ft_putstr_fd(": Unexpected error\n", 2);
            return (1);
    }
}