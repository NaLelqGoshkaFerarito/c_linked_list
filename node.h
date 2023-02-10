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
    prev_node->next = current_node;
}

void set_next(node* current_node, node* next_node){
    current_node->next = next_node;
    next_node->prev = current_node;
}

void set_prev_next(node* current_node, node* prev_node, node* next_node){
    set_next(current_node, next_node);
    set_prev(current_node, prev_node);
}

void swap(node* n1, node* n2){
    float temp_data = 0;
    temp_data = n1->data;
    n1->data = n2->data;
    n2->data = temp_data;
}
#endif //LINKED_LIST_NODE_H
