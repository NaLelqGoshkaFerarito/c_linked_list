//
// Created by vladi on 6 Feb 2023.
//

#ifndef LINKED_LIST_LL_H
#define LINKED_LIST_LL_H
#include "node.h"

typedef struct linked_list{
    node* first;
    node* last;
}linked_list;

//initialize list with only one node
void llist_init_f(linked_list* ll, node* first){
    ll->first = first;
    ll->last = first;
}

//initialize list with two nodes
void llist_init_fl(linked_list* ll, node* first, node* last){
    ll->first = first;
    ll->last = last;
}

void llist_append(linked_list* ll, node* app){
    ll->last->next = app;
    ll->last = app;
}

void llist_prepend(linked_list* ll, node* prep){
    ll->first->prev = prep;
    ll->first = prep;
}
#endif //LINKED_LIST_LL_H
