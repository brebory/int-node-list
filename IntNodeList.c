//
//  list.c
//  lists
//
//  Created by Brendon Roberto on 2/14/13.
//  Copyright (c) 2013 Brendon Roberto. All rights reserved.
//

#include <stdlib.h>
#include "IntNodeList.h"

/*
 * Creates a new nodeList with one node*, `item`,
 * containing int `element`, with member
 * `prev` pointing to the NULL pointer.
 * Returns a pointer to this nodeList `this`.
 */

nodeList* IntNodeList(int element) {
    nodeList* list = malloc(sizeof(nodeList));
    if (list == NULL) {
        free(list);
        return NULL;
    }
    
    node* item = IntNode(element);

    item->element = element;
    item->prev = NULL;
    list->top = item;
    
    return list;
}

/*
 * Creates a new node* containing
 * int `element`, with member `prev` pointing
 * to the NULL pointer. Returns this
 * newly created node*.
 * Generally, this function is for internal
 * use only - a node* is pretty useless by itself.
 */

node* IntNode(int element) {
    node* node = malloc(sizeof(node));
    if (node == NULL) {
        free(node);
        return NULL;
    }
    
    node->element = element;
    node->prev = NULL;
    
    return node;
}

nodeList* INL_reverse(nodeList* this) {
    //implement
    return NULL;
}

/*
 * Clones a `new` nodeList* from given nodeList* `source`.
 * The two are separate instances in memory, and `source`
 * is not modified in the process, but every node in `new` 
 * derives it's element from `source`.
 */

nodeList* INL_clone(nodeList* source) {
    node* head = source->top;
    nodeList* reverse = IntNodeList(source->top->element);
    nodeList* new;
    
    // I don't know if this is the most effecient implementation of this. I don't know how to not copy the list backward.
    
    while ((source->top = source->top->prev) != NULL) {
        INL_push(reverse, source->top->element);
    }
    
    new = IntNodeList(reverse->top->element);
    
    while ((reverse->top = reverse->top->prev) != NULL) {
        INL_push(new, reverse->top->element);
    }
    
    source->top = head;
    free(reverse);
    return new;
}

/*
 * Adds a new node containing `element`
 * to the existing IntNodeList `this`.
 * Uses INL_traverse to make sure that the new
 * node is added to the end of `this`.
 * The new node has members `element = element`,
 * `next = NULL`, and `prev = this`;
 */

void INL_push(nodeList* this, int element) {
    node* node = IntNode(element);
    if (node == NULL)
        return;
    
    node->prev = this->top;
    this->top = node;
}

/*
 * Sets the current `top` node to `old`,
 * moves the `top` pointer to the previous node,
 * then frees the `old` node.
 * Finally, returns the `int element` inside of `old`.
 */

int INL_pop(nodeList* this) {
    node* old = this->top;
    int element = old->element;
    
    this->top = this->top->prev;
    
    free(old);
    
    return element;
}


bool INL_search(nodeList* this, int term) {
    
    //implement
    return NULL;
}

/*
 * ASIDE:
 * Using an idiom similar to Ruby here: Higher order functions
 * that modify in place are suffixed by an `_`. It would be an `!`
 * as per the Ruby standard, but `!`'s aren't permitted in C function names.
 * However, I'm not exactly sure how to implement the "destructive" version
 * of this algorithm. Also, I'm pretty sure it causes memory leaks.
 */

nodeList* INL_filter_(nodeList* this, bool (*func)(node* item)) {
    node* head = this->top;
    nodeList* reverse = NULL;
    nodeList* new;
    
    do {
        if (func(this->top)) {
            if (reverse == NULL) {
                reverse = IntNodeList(this->top->element);
            } else {
                INL_push(reverse, this->top->element);
            }
        }
     } while ((this->top = this->top->prev) != NULL);

    this->top = head;
    
    new = IntNodeList(reverse->top->element);
    
    while ((reverse->top = reverse->top->prev) != NULL) {
        INL_push(new, reverse->top->element);
    }

    free(reverse);
    
    return new;
}

nodeList* INL_filter(nodeList* this, bool (*func)(node* item)) {
    node* head = this->top;
    nodeList* reverse = NULL;
    nodeList* new;
    
    do {
        if (func(this->top)) {
            if (reverse == NULL) {
                reverse = IntNodeList(this->top->element);
            } else {
                INL_push(reverse, this->top->element);
            }
        }
    } while ((this->top = this->top->prev) != NULL);
    
    this->top = head;
    
    new = IntNodeList(reverse->top->element);
    
    while ((reverse->top = reverse->top->prev) != NULL) {
        INL_push(new, reverse->top->element);
    }
    
    free(reverse);
    
    return new;
}

nodeList* INL_map_(nodeList* this, int (*func)(int element)) {
    node* head = this->top;
    
    do {
        this->top->element = func(this->top->element);
    } while ((this->top = this->top->prev) != NULL);
    
    this->top = head;
    
    return this;
}

int INL_reduce(nodeList* this, int (*func)(node* item)) {
    node* head = this->top;
    int combine = 0;

    do {
        combine += func(this->top);
    } while ((this->top = this->top->prev) != NULL);
    
    this->top = head;
    
    return combine;
}
