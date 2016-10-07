/*
**文件：list.c
**时间：2016.10.07 15:40:01
**作者：Leon
**功能：
*/

#include "list.h"

inline void list_add(List *head, List *_new)
{
    _new->next = head->next;
    head->next = _new;
    _new->prev = _new->next->prev;
    _new->next->prev = _new;
}

inline void __list_del(List *prev, List *next)
{
    prev->next = next;
    next->prev = prev;
}

inline void list_del(List *node)
{
    __list_del(node->prev, node->next);
}

