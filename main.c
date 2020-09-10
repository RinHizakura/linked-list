#include "linked_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  node_t *head = NULL;
  srand(time(NULL));

  for (int num = 100; num <= 5000; num += 200) {
    for (int i = 0; i < num; i++) {
      add_entry(&head, (rand() % 1000));
    }
    swap_pair(&head);
    delete_list(&head);
  }

  return 0;
}
