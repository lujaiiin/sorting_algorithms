#include "sort.h"

/**
 * switch_node - exchange 2 nodes
 * @node1: pointer to first node
 * @node2: pointer to second node
 * Return: pointer to smaller node value
 */

listint_t *switch_node(listint_t *node1, listint_t *node2)
{
listint_t *prev_node = node1->prev;
listint_t *next_node = node2->next;

if (prev_node)
prev_node->next = node2;
if (next_node)
next_node->prev = node1;

node1->next = next_node;
node1->prev = node2;
node2->next = node1;
node2->prev = prev_node;

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

if (!prv_node->prev)
*list = key;

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
