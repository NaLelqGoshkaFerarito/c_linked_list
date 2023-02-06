#include <stdio.h>
#include "node.h"
int main() {

    node node1;
    node node2;
    node node3;
    initialize_node(&node1, 16.5f, NULL, NULL);
    initialize_node(&node2, 16.6f, &node1, NULL);
    initialize_node(&node3, 16.7f, &node2, NULL);

    set_next(&node1, &node2);
    set_next(&node2, &node3);

    printf("%.2f", node1.next->data);
    printf("\n");
    printf("%.2f", node1.next->next->data);
    printf("\n");

    set_next(&node3, &node1);
    printf("%.2f", node1.next->next->next->data);
    printf("\n");
    return 0;
}
