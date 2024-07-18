#ifndef FT_LS
#define FT_LS

#include <stdbool.h>
#include <libft.h>
#include <dirent.h>

#define ERROR_USAGE "usage: ft_ls [-lRart] [file ...]"
#define ERROR_DIRECTORY "ft_ls: %s: No such file or directory"
/*
-l      (The lowercase letter “ell”.) List files in the long format, as described in the The Long Format subsection below.
-R      Recursively list subdirectories encountered.
-a      Include directory entries whose names begin with a dot (‘.’).
-r      Reverse the order of the sort.
-t      Sort by descending time modified (most recently modified first).  If two files have the same modification timestamp, sort their names in ascending lexicographical order.  The -r option reverses both of these sort
        orders.
*/

typedef struct s_ls{
    bool list_flag;
    bool recursive_flag;
    bool hidden_flag;
    bool reverse_flag;
    bool time_flag;
    t_list *directories;
} t_ls;

int parseArguments(int argc, char **argv, t_ls *ls);

/*DEBUG*/
void printFlags(t_ls *ls);
void printDirectories(t_ls *ls);

int printDirectory(const t_ls *restrict ls);

/*DIRECTORIES*/
int processArguments(t_ls *ls);
int directoryError(const char *restrict name);

int showDirectory(const t_ls *restrict ls, const char *restrict name, const int namelen);
int writeSpace(const int index, const int size, struct dirent *dir_data);
void newLine(const t_ls *restrict ls, const char *restrict path);

#endif