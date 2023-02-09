#include <stdio.h>
#include <assert.h>
#include "node.h"
#include "ll.h"

void test_node();
void test_linked_list_basic();
void test_linked_list_index();
void test_linked_list_append();
void test_linked_list(){
    test_linked_list_index();
    test_linked_list_basic();
    test_linked_list_append();
}

void test_all(){
    test_node();
    test_linked_list();
}

int main() {
    test_all();
    return 0;
}

#if DYNAMIC
void test_linked_list_basic(){
    printf("\nCommencing basic list test\n");

    linked_list list;
    llist_init(&list);
    llist_prepend(&list, 16.5f);
    llist_prepend(&list, 16.6f);
    llist_prepend(&list, 16.7f);

    llist_print(&list);

    llist_prepend(&list, 16.4f);
    llist_prepend(&list, 16.3f);
    llist_prepend(&list, 16.2f);

    llist_print(&list);

    llist_destroy(&list);

    printf("Basic list test was a success\n\n");
}

void test_linked_list_index(){
    printf("\nCommencing basic list test\n");
    linked_list list;
    llist_init(&list);
    assert(NULL == get_at(&list, 2));
    llist_prepend(&list, 16.5f);
    llist_prepend(&list, 16.6f);
    llist_prepend(&list, 16.7f);

    assert(16.5f == get_at(&list, 2)->data);

    llist_prepend(&list, 16.4f);
    llist_prepend(&list, 16.3f);
    llist_prepend(&list, 16.2f);

    assert(16.2f == get_at(&list, 0)->data);
    printf("Basic linked list indexing test was a success\n\n");
}

void test_linked_list_append(){
    printf("\nCommencing linked list appending test\n");
    linked_list list;
    llist_init(&list);
    assert(NULL == get_at(&list, 2));
    llist_prepend(&list, 16.5f);
    llist_prepend(&list, 16.6f);
    llist_prepend(&list, 16.7f);

    llist_print(&list);
    assert(16.5f == get_at(&list, 2)->data);

    llist_append(&list, 16.4f);
    llist_append(&list, 16.3f);
    llist_append(&list, 16.2f);

    llist_print(&list);
    assert(16.2f == get_at(&list, 5)->data);
    printf("Linked list appending test was a success\n\n");
}

void test_node(){
    printf("\nCommencing node test\n");

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
    printf("Node test success\n\n");
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