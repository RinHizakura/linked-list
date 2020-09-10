#include "linked_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  node_t *head = NULL;
  srand(time(NULL));

  for (int num = 10; num < 2000; num++) {
    for (int i = 0; i < num; i++) {
      add_entry(&head, (rand() % 1000));
    }

    struct timespec tt1, tt2;
    clock_gettime(CLOCK_MONOTONIC, &tt1);
    swap_pair(&head);
    clock_gettime(CLOCK_MONOTONIC, &tt2);

    long long time = (long long)(tt2.tv_sec * 1e9 + tt2.tv_nsec) -
                     (long long)(tt1.tv_sec * 1e9 + tt1.tv_nsec);

    delete_list(&head);

    for (int i = 0; i < num; i++) {
      add_entry(&head, (rand() % 1000));
    }
    clock_gettime(CLOCK_MONOTONIC, &tt1);
    swap_pair_by_value(&head);
    clock_gettime(CLOCK_MONOTONIC, &tt2);

    long long time2 = (long long)(tt2.tv_sec * 1e9 + tt2.tv_nsec) -
                      (long long)(tt1.tv_sec * 1e9 + tt1.tv_nsec);

    printf("%d, %lld, %lld\n", num, time, time2);
    delete_list(&head);
  }

  return 0;
}
