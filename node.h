//
// Created by vladi on 6 Feb 2023.
//



#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H
#define DYNAMIC 1 //1 if dynamic memory allocation is
#include <stdlib.h>

typedef struct node{
    float data;
    struct node* next;
    struct node* prev;
}node;



#if DYNAMIC
//pass a pointer to a node which is to be initialized and its members
node* node_init(float data, node* prev, node* next){
    node* current_node = (node*) malloc(sizeof(node));
    current_node->data = data;
    current_node->next = next;
    current_node->prev = prev;
    return current_node;
}

//initialize node with no next and previous
node* node_init_hanging(float data){
    return node_init(data, NULL, NULL);
}

//free the memory allocated in one of the node_init function
void node_destroy(node* tbd){
    free(tbd);
}

#else

//pass a pointer to a node which is to be initialized and its members
void node_init(node* current_node, float data, node* prev, node* next){
    current_node->data = data;
    current_node->next = next;
    current_node->prev = prev;
}
}
#endif //DYNAMIC

void set_prev(node* current_node, node* prev_node){
    current_node->prev = prev_node;
}

void set_next(node* current_node, node* next_node){
    current_node->next = next_node;
}

void set_prev_next(node* current_node, node* prev_node, node* next_node){
    current_node->prev = prev_node;
    current_node->next = next_node;
}
#endif //LINKED_LIST_NODE_H
