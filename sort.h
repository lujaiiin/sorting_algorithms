#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

/*helper funcion*/
void swp(int *x, int *y);
listint_t *switch_node(listint_t *node1, listint_t *node2);
int Lomuto(int *array, size_t size, size_t start, size_t end);
void quick_reco(int *array, size_t start, size_t end, size_t size);

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*tasks functions*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);




#endif
