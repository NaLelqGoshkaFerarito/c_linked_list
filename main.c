#include <stdio.h>
#include <assert.h>
#include "node.h"
#include "ll.h"

void test_node();
void test_linked_list_basic();

int main() {
//    test_node();
    test_linked_list_basic();
    return 0;
}

#if DYNAMIC
void test_linked_list_basic(){
    linked_list list;
    llist_init(&list);
    llist_prepend(&list, 16.5f);
    llist_prepend(&list, 16.6f);
    llist_prepend(&list, 16.7f);

    llist_prepend(&list, 16.4f);
    llist_prepend(&list, 16.3f);
    llist_prepend(&list, 16.2f);

    llist_destroy(&list);

    printf("Basic list text was a success\n");
}
void test_node(){
    node* node1 = node_init_hanging(16.5f);
    node* node2 = node_init(16.6f, node1, NULL);
    node* node3 = node_init(16.7f, node2, NULL);

    set_next(node1, node2);
    set_next(node2, node3);

    //aka node2

    assert(node1->next->data == 16.6f);
    //aka node3
    assert(node1->next->next->data == 16.7f);


    set_next(node3, node1);
    //aka node1
    assert(node1->next->next->next->data == 16.5f);

    free(node1);
    free(node2);
    free(node3);
    printf("Node test success\n");
}
#else
void test_node(){
    node node1;
    node node2;
    node node3;
    node_init(&node1, 16.5f, NULL, NULL);
    node_init(&node2, 16.6f, &node1, NULL);
    node_init(&node3, 16.7f, &node2, NULL);

    set_next(&node1, &node2);
    set_next(&node2, &node3);

    //aka node2

    assert(node1.next->data == 16.6f);
    //aka node3
    assert(node1.next->next->data == 16.7f);


    set_next(&node3, &node1);
    //aka node1
    assert(node1.next->next->next->data == 16.5f);
    printf("Node test success\n");
}
}
#endif //DYNAMIC