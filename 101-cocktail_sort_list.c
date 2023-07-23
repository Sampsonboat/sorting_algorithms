#include <stdio.h>
#include <stdlib.h>

typedef struct listint_t {
    int n;
    struct listint_t *prev;
    struct listint_t *next;
} listint_t;

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2) {
    if (!node1 || !node2)
        return;

    if (node1->prev)
        node1->prev->next = node2;
    if (node2->next)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;

    node1->prev = node2;
    node2->next = node1;

    if (*list == node1)
        *list = node2;
}

void cocktail_sort_list(listint_t **list) {
    if (!list || !(*list) || !(*list)->next)
        return;

    int swapped;
    listint_t *start = NULL;
    listint_t *end = NULL;

    do {
        swapped = 0;
        listint_t *current = *list;

        while (current->next != end) {
            if (current->n > current->next->n) {
                swap_nodes(list, current, current->next);
                swapped = 1;
                print_list(*list);
            } else {
                current = current->next;
            }
        }

        if (!swapped)
            break;

        end = current;

        swapped = 0;
        while (current->prev != start) {
            if (current->n < current->prev->n) {
                swap_nodes(list, current->prev, current);
                swapped = 1;
                print_list(*list);
            } else {
                current = current->prev;
            }
        }

        start = current;

    } while (swapped);
}

/* Utility function to create a new node */
listint_t *create_node(int n) {
    listint_t *new_node = (listint_t *)malloc(sizeof(listint_t));
    if (!new_node) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

/* Utility function to add a node to the end of the list */
void add_node_end(listint_t **list, int n) {
    listint_t *new_node = create_node(n);
    if (!(*list)) {
        *list = new_node;
    } else {
        listint_t *current = *list;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
}

/* Utility function to print the list */
void print_list(listint_t *list) {
    while (list) {
        printf("%d ", list->n);
        list = list->next;
    }
    printf("\n");
}

int main() {
    listint_t *list = NULL;

    // Add elements to the list
    add_node_end(&list, 9);
    add_node_end(&list, 3);
    add_node_end(&list, 7);
    add_node_end(&list, 5);
    add_node_end(&list, 1);
    add_node_end(&list, 8);
    add_node_end(&list, 2);
    add_node_end(&list, 6);
    add_node_end(&list, 4);

    printf("Original list: ");
    print_list(list);

    cocktail_sort_list(&list);

    printf("Sorted list: ");
    print_list(list);

    return 0;
}

