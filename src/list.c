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

inline int list_empty(List *head)
{
    return (head == head->next);
}

/*将该节点移动到另一个链表head节点后面*/
inline void list_move(List *node, List *head)
{
    list_del(node);
    list_add(head, node);
}

/*将该节点移动到另一个链表head的末尾（head之前）*/
inline void list_move_tail(List *node, List *head)
{
    list_del(node);
    list_add_tail(head, node);
}

/*将该srchead链表添加到另一个disthead链表节点head的后面*/
void list_splice(List *srchead, List *disthead)
{
    if(list_empty(srchead)) return;
    List *shead = srchead->next;
    list_del(srchead);
    List *stail = shead->prev;

    stail->next = disthead->next;
    disthead->next = shead;
    shead->prev = disthead;
    stail->next->prev = stail;

}




