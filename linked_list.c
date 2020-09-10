#include "linked_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void add_entry(node_t **head, int new_value) {
  node_t **indirect = head;

  node_t *new_node = malloc(sizeof(node_t));
  assert(new_node);
  new_node->value = new_value;
  new_node->next = NULL;

  while (*indirect)
    indirect = &(*indirect)->next;

  *indirect = new_node;
}

node_t *find_entry(node_t *head, int value) {
  node_t *current = head;
  for (; current && current->value != value; current = current->next)
    /* interate */;
  return current;
}

void remove_entry(node_t **head, node_t *entry) {
  node_t **indirect = head;

  while ((*indirect) != entry)
    indirect = &(*indirect)->next;

  *indirect = entry->next;
  free(entry);
}

void delete_list(node_t **head) {

  while (*head) {
    node_t *next = (*head)->next;
    free(*head);
    *head = next;
  }
}

void swap_pair(node_t **head) {

  for (node_t **node = head; *node && (*node)->next;
       node = &((*node)->next->next)) {
    node_t *tmp = *node;
    *node = (*node)->next;
    tmp->next = (*node)->next;
    (*node)->next = tmp;
  }
}

void swap_pair_by_value(node_t **head) {

  for (node_t **node = head; *node && (*node)->next;
       node = &((*node)->next->next)) {
    XORSWAP_UNSAFE((*node)->value, (*node)->next->value);
  }
}

node_t *reverse(node_t *head) {
  node_t *cursor = NULL;
  while (head) {
    node_t *next = head->next;
    head->next = cursor;
    cursor = head;
    head = next;
  }
  return cursor;
}

void print_list(node_t *head) {
  for (node_t *current = head; current; current = current->next)
    printf("%d ", current->value);
  printf("\n");
}
