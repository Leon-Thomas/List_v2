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
    return 0;
}
