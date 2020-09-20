#include "linked_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void add_entry(node_t **head, int new_value)
{
    node_t **indirect = head;

    node_t *new_node = malloc(sizeof(node_t));
    assert(new_node);
    new_node->value = new_value;
    new_node->next = NULL;

    while (*indirect)
        indirect = &(*indirect)->next;

    *indirect = new_node;
}

node_t *find_entry(node_t *head, int value)
{
    if (!head)
        return NULL;

    node_t *current = head;
    for (; current && current->value != value; current = current->next)
        /* interate */;
    return current;
}

void remove_entry(node_t **head, node_t *entry)
{
    if (!head)
        return;

    node_t **indirect = head;

    while ((*indirect) != entry)
        indirect = &(*indirect)->next;

    *indirect = entry->next;
    free(entry);
}

void delete_list(node_t **head)
{
    while (*head) {
        node_t *next = (*head)->next;
        free(*head);
        *head = next;
    }
}

void swap_pair(node_t **head)
{
    for (; *head && (*head)->next; head = &((*head)->next->next)) {
        node_t *tmp = *head;
        *head = (*head)->next;
        tmp->next = (*head)->next;
        (*head)->next = tmp;
    }
}

void swap_pair_by_value(node_t **head)
{
    for (; *head && (*head)->next; head = &((*head)->next->next)) {
        XORSWAP_UNSAFE((*head)->value, (*head)->next->value);
    }
}

void reverse(node_t **head)
{
    if (!head)
        return;

    node_t *prev = NULL;
    node_t *next = (*head)->next;

    (*head)->next = prev;
    while (next) {
        prev = (*head);
        *head = next;
        next = next->next;
        (*head)->next = prev;
    }
}
void recursive_rev(node_t **head)
{
    if (!head)
        return;

    recursive_rev_step(*head, NULL, head);
}

void recursive_rev_step(node_t *curr, node_t *prev, node_t **head)
{
    node_t *next = curr->next;
    curr->next = prev;

    if (!next) {
        *head = curr;
        return;
    }

    recursive_rev_step(next, curr, head);
}

void shuffle(node_t **head)
{
    srand(time(NULL));

    // First, we have to know how long is the linked list
    int len = 0;
    node_t **indirect = head;
    while (*indirect) {
        len++;
        indirect = &(*indirect)->next;
    }

    // Append shffling result to another linked list
    node_t *new = NULL;
    node_t **new_head = &new;
    node_t **new_tail = &new;

    while (len) {
        int random = rand() % len;
        indirect = head;


        while (random--)
            indirect = &(*indirect)->next;

        node_t *tmp = *indirect;
        *indirect = (*indirect)->next;

        tmp->next = NULL;
        if (new) {
            (*new_tail)->next = tmp;
            new_tail = &(*new_tail)->next;
        } else
            new = tmp;

        len--;
    }

    *head = *new_head;
}

void print_list(node_t *head)
{
    for (node_t *current = head; current; current = current->next)
        printf("%d ", current->value);
    printf("\n");
}
