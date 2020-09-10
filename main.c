#include "linked_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  node_t *head = NULL;
  srand(time(NULL));

  for (int i = 0; i < 10; i++) {
    add_entry(&head, (rand() % 1000));
  }
  printf("Prev: \n");
  print_list(head);
  reverse(&head);
  printf("After: \n");
  print_list(head);
  delete_list(&head);

  return 0;
}
