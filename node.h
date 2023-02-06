//
// Created by vladi on 6 Feb 2023.
//

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

typedef struct node{
    float data;
    struct node* next;
    struct node* prev;
}node;

//pass a pointer to a node which is to be initialized and its members
void initialize_node(node* current_node, float data, node* prev, node* next){
    current_node->data = data;
    current_node->next = next;
    current_node->prev = prev;
}

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
