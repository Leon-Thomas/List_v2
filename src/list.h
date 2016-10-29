#ifndef LIST_H
#define LIST_H
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif //C++
typedef struct list_node
{
    struct list_node *next;
    struct list_node *prev;
}List;

//用来获取包含链表节点的结构体的地址
#define container_of(ptr, type, member) \
    ({ const typeof( ((type *)0)->member) *mptr = (ptr); \
       (type *)( (char *)mptr - offsetof(type,member)); \
     }) 

#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)

/*链表头初始化
 * @head_ptr: 头节点地址
 * */
#define list_init(head_ptr) \
    do {(head_ptr)->next = (head_ptr);(head_ptr)->prev = (head_ptr);}while(0)

//添加一个节点到指定节点后面
void list_add(List *head, List *_new);
//将节点添加到链尾
void list_add_tail(List *head, List *_new);
//从链表中删除该节点(并不释放内存)
void __list_del(List *prev, List *next);
void list_del(List *node);
//从链表中删除该节点并释放内存
#define list_del_free(node,type,member) \
    do{type *__tp=list_entry(node,type,member);list_del(node);free(__tp);}while(0)

//将该节点移动到另一个链表head节点后面
void list_move(List *node, List *head);
//将该节点移动到另一个链表head的末尾（head之前）
void list_move_tail(List *node, List *head);
//判断链表是否为空，是返回1，否返回0
int list_empty(List *head);
//将strhead链表添加到disthead链表节点head的后面
void list_splice(List *srchead, List *disthead);

/*遍历链表*/
/*
 * @ptr: 链表节点指针
 * @list: 链表头指针
 */ 
#define list_for_each(ptr, list) \
for( (ptr)=(list)->next; (ptr)!=(list); (ptr)=(ptr)->next )  

/*安全的遍历链表，遍历过程中可改变链表长度
 * @ptr: 链表结构指针变量，用于访问链表节点
 * @tmp: 链表结构指针变量，用于暂存下一个链表节点
 * @list: 链表头节点，遍历时并不访问该节点*/
#define list_for_each_safe(ptr, tmp, list)    \
    for(tmp=ptr=(list)->next;tmp=tmp->next,ptr!=list;ptr = tmp)

/*遍历链表
 * @ptr: 指向包含链表结构的结构体指针
 * @head: 链表头指针
 * @memb er: 链表节点在结构体中的成员名字*/
#define list_for_each_entry(ptr, head, member)                  \
    for( (ptr)=list_entry((head)->next,typeof(*(ptr)),member); \
            (ptr)!=list_entry(head,typeof(*(ptr)),member);      \
            (ptr)=list_entry((ptr)->member.next,typeof(*(ptr)),member)) 

/*安全的遍历链表,可在遍历时改变链表长度。
 * @ptr: 结构体指针，用于访问用户节点
 * @tmp: 结构体指针，用于临时保存下个节点的地址
 * @head: 链表头指针，遍历时并不访问头节点
 * @member: 链表结构在用户数据结构中的变量名*/
#define list_for_each_entry_safe(ptr, tmp, head, member)    \
    for(tmp=ptr=list_entry((head)->next,typeof(*(ptr)),member);   \
            tmp=list_entry((tmp)->member.next,typeof(*(ptr)),member), ptr!=list_entry(head,typeof(*(ptr)),member);  \
            ptr=tmp)



#ifdef __cplusplus
}
#endif //C++

#endif //LIST_H
