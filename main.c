#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"

int main()
{
    node_t *head = NULL;
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        add_entry(&head, i);
    }
    printf("Prev: \n");
    print_list(head);


    printf("After: \n");

    shuffle(&head);
    print_list(head);
    delete_list(&head);

    return 0;
}
