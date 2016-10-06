#ifndef LIST_H
#define LIST_H
#include <stddef.h>

typedef struct list_node
{
    struct list_node *next;
    struct list_node *prev;
}List;


#endif //LIST_H
