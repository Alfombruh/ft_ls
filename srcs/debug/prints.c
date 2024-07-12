#include "ft_ls.h"
#include "ft_printf.h"
#include "colors.h"

void printFlags(t_ls *ls){
    if (!ls->hidden_flag && !ls->list_flag && !ls->list_flag && !ls->recursive_flag && !ls->reverse_flag && !ls->time_flag){
        ft_printf( BHRED "No flags were selected\n" CLOSE);
        return;
    }
    ft_printf(BHBLU "FLAGS ARE-> " CLOSE);
    ft_printf(BHWHT "-");
    if (ls->list_flag)
        ft_printf("l");
    if (ls->recursive_flag)
        ft_printf("R");
    if (ls->hidden_flag)
        ft_printf("a");
    if (ls->reverse_flag)
        ft_printf("r");
    if (ls->time_flag)
        ft_printf("t");
    ft_printf(CLOSE "\n");
}

void printDirectories(t_ls *ls){
    t_list *temp = ls->directories;
    ft_printf(BHYEL "DIRECTORIES ARE-> " CLOSE);
    while(temp){
        ft_printf(BHWHT "%s ", (char *)temp->content);
        temp = temp->next;
    }
    ft_printf(CLOSE "\n");
}