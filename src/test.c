/*
**文件：test.c
**时间：2016.10.06 17:20:29
**作者：Leon
**功能：测试链表
*/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct test
{
    char flag;
    int data;
    List node;  //链表节点
};

int main()
{
    struct test head;

    list_init(&head.node);
    struct test *p = NULL;
    for(int i=0;i < 5;++i)
    {
        p = malloc(sizeof(struct test));
        p->data = i;
        list_add(&head.node, &p->node);
    }

    List *lp;
    list_for_each(lp, &head.node)
    {
        struct test *tp = list_entry(lp,struct test,node);
        printf("data:%d\n",tp->data);
    }

    printf("------------------------\n");

    struct test *tp;
    list_for_each_entry(tp, &head.node, node)
    {
        printf("data:%d\n",tp->data);
    }
    
    printf("--------delete----------------\n");

    tp = list_entry(head.node.next,struct test,node);
    list_del(&tp->node);
    free(tp);
    list_for_each_entry(tp, &head.node, node)
    {
        printf("data:%d\n",tp->data);
    }

    printf("--------delete and free--------\n");
    list_del_free(head.node.next,struct test,node);
    list_for_each_entry(tp, &head.node, node)
    {
        printf("data:%d\n",tp->data);
    }    

    printf("---------------\n");
    struct test head2;
    list_init(&head2.node);
    for(int i=0;i < 5;++i)
    {
        p = malloc(sizeof(struct test));
        p->data = i;
        list_add(&head2.node, &p->node);
    }
    list_for_each_entry(tp,&head2.node,node)
    {
        printf("list2:%d\n",tp->data);
    }


    printf("-------list_move--------\n");
    /*lp = head.node.next;
    list_del(lp);
    list_add(&head2.node,lp);*/
    list_move(head.node.next,&head2.node);
    printf("----after move list1----\n");
    list_for_each_entry(tp,&head.node,node)
    {
        printf("list1:%d\n",tp->data);
    }
    printf("----after move list2----\n");
    list_for_each_entry(tp,&head2.node,node)
    {
        printf("list2:%d\n",tp->data);
    }

    
    printf("-------list_move_tail--------\n");
    list_move_tail(head2.node.next->next,&head.node);
    printf("----after move list1----\n");
    list_for_each_entry(tp,&head.node,node)
    {
        printf("list1:%d\n",tp->data);
    }
    printf("----after move list2----\n");
    list_for_each_entry(tp,&head2.node,node)
    {
        printf("list2:%d\n",tp->data);
    }

    printf("-------list_splice-----\n");

    list_splice(&head2.node,&head.node);
    printf("----after splice list1----\n");
    list_for_each_entry(tp,&head.node,node)
    {
        printf("list1:%d\n",tp->data);
    }

    printf("----after splice list2----\n");
    list_for_each_entry(tp,&head2.node,node)
    {
        printf("list2:%d\n",tp->data);
    }
    return 0;
}
