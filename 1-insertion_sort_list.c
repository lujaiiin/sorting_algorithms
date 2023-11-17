#include "sort.h"

/**
 * switch_node - exchange 2 nodes
 * @node1: pointer to first node
 * @node2: pointer to second node
 * Return: pointer to smaller node value
 */

listint_t *switch_node(listint_t *node1, listint_t *node2)
{
listint_t *tmp = NULL;

if (node2->next)  /*handle last node*/
{
tmp = node2->next;
node2->next->prev = node1;
}
if (node1->prev) /*handle first node*/
node1->prev->next = node2;
else
node2->prev = NULL;

node2->prev = node1->prev;
node2->next = node1;
node1->prev = node2;
node1->next = tmp;
return (node2);
}

/**
 * insertion_sort_list - sort list ascendingly
 * @list: doubly linked list
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{

listint_t *h, *key, *prv_node;
h = *list;
if (!h->next || !h)
return;

h = h->next;
while (h) /*loop from second node*/
{
key = h; /*second node*/
h = h->next; /*enusre fixing h of swap*/

while (key->prev) /*switch nodes*/
{
prv_node = key->prev;
if (key->n < prv_node->n)
{
key = switch_node(prv_node, key);
if (!key->prev)
*list = key;
print_list(*list);
}
else
break;
}
}
}
