//
// Created by vladi on 6 Feb 2023.
//

#ifndef LINKED_LIST_LL_H
#define LINKED_LIST_LL_H
#include "node.h"

typedef struct linked_list{
    node* first;
}linked_list;

void llist_init(linked_list* ll){
    ll->first = NULL;
}

#if DYNAMIC
//void llist_append(linked_list* ll, float data){
//    node* app = node_init_hanging(data);
//    //if the list is empty first and last both become app
//    if (ll->first == NULL){
//        ll->first = app;
//        ll->last = app;
//        return;
//    }
//    set_next(ll->last, app);
//    ll->last = app;
//}

void llist_prepend(linked_list* ll, float data){
    node* prep = node_init_hanging(data);
    //if the list is empty first and last both become prep
    if (ll->first == NULL){
        ll->first = prep;
        return;
    }
    set_prev(ll->first, prep);
    ll->first = prep;
}

void llist_destroy(linked_list* ll){
    node* curr_node = ll->first;
    node* next_node = ll->first->next;
    while (next_node != NULL){
        free(curr_node);
        curr_node = next_node;
        next_node = next_node->next;
    }
}

#else
void llist_append(linked_list* ll, node* app){
    //if the list is empty first and last both become app
    if (ll->first == NULL){
        ll->first = app;
        ll->last = app;
        return;
    }
    ll->last->next = app;
    ll->last = app;
}

void llist_prepend(linked_list* ll, node* prep){
    //if the list is empty first and last both become prep
    if (ll->first == NULL){
        ll->first = prep;
        ll->last = prep;
        return;
    }
    ll->first->prev = prep;
    ll->first = prep;
}
#endif //DYNAMIC
//gets node at index
node* index(linked_list* ll, int index){
    node* curr_node = ll->first;
    for (int i = 0; i < index; ++i) {
        if ((curr_node = curr_node->next) == NULL){
            return NULL;
        }
    }
    return curr_node;
}
#endif //LINKED_LIST_LL_H
