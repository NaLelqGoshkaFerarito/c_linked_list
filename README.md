# c_linked_list
Simple doubly-linked list implementation in C

## node.h
Contains the implementation of the `node` struct and the functions it needs to operate properly.

### The `node` struct
- `float data` - contains a float
- `node* next` and `node* prev` - contain pointers to the next and previous node respectively

### Functions
- `node* node_init` - returns a pointer to a `malloc`ed node and sets the previous and next nodes of that node
- `node* node_init_hanging` - same as the previous functions, but both `prev` and `next` are set to `NULL`
- `void set_prev` - sets the previous node and the next node of the previous node
- `void set_next` - sets the next node and the previous node of the next node
- `void set_prev_next` - combines the functionality of the last two functions
- `void swap` - swaps the data of the two given nodes
## ll.h
Contains the implementation of the `linked_list` struct and various functions that make using it easier to navigate

### The `linked_list` struct
- `node* first` - points to the head of the list

### Functions
- `void llist_init` - initialize a list that is passed to this function; done by setting the head to `NULL` (otherwise the other functions will try to access an illegal address)
- `void llist_destroy` - iterates over a list and frees all the nodes
- `void llist_prepend` - inserts a new element at index 0 and shifts all other elements to the right
- `void llist_append` - inserts a new element at the end of the list (for efficiency reasons, `llist_prepend` is generally a better option for inserting)
- `void llist_print` - prints all of the elements in a list
- `node* get_at` - returns a pointer to the node at that index
