#include "sort.h"

/**
 * switch_node2 - exchange 2 nodes
 * @node1: pointer to first node
 * @node2: pointer to second node
 * Return: pointer to smaller node value
 */

listint_t *switch_node2(listint_t *node1, listint_t *node2)
{

if (node2->next) /* handle node next to node2*/
node2->next->prev = node1;

if (node1->prev) /* handle node previou to node1*/
node1->prev->next = node2;

node1->next = node2->next;
node2->prev = node1->prev;

node1->prev = node2;
node2->next = node1;
return (node2);
}

/**
 * cocktail_sort_list - sort list ascendingly
 * @list: doubly linked list
 * Return: nothing
 */

void cocktail_sort_list(listint_t **list)
{
listint_t *tail, *t, *h = *list;
int isswaped = 1;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
while (isswaped)
{
isswaped = 0;

while (h->next) /*move bigger node to the end*/
{
if (h->n > h->next->n)
{
h = switch_node2(h, h->next);  /*update h*/
if (!h->prev) /*update head*/
*list = h;
print_list(*list);
isswaped = 1;
}
h = h->next;
}
tail = h;
t = tail;
while (t->prev)  /*move smaller node to start*/
{
if (t->n < t->prev->n)
{
t = switch_node2(t->prev, t)->next; /*update t*/
if (!t->prev->prev) /*update head*/
*list = t->prev;
print_list(*list);
isswaped = 1;
}
t = t->prev;
}
}
}
