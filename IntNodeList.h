//
//  list.h
//  lists
//
//  Created by Brendon Roberto on 2/14/13.
//  Copyright (c) 2013 Brendon Roberto. All rights reserved.
//

#ifndef intnodelist_h
#define intnodelist_h

#include <stdbool.h>

typedef struct node {
    int element;
    struct node* prev;
}
node;

typedef struct {
    node* top;
}
nodeList;

nodeList* IntNodeList(int);

node* IntNode(int);

nodeList* INL_clone(nodeList*);

void INL_push(nodeList*, int);

int INL_pop(nodeList*);

bool INL_search(nodeList*, int);

nodeList* INL_filter_(nodeList*, bool (*)(node*));

nodeList* INL_filter(nodeList*, bool (*)(node*));

nodeList* INL_map_(nodeList*, int (*)(int));

nodeList* INL_map(nodeList*, int (*)(int));

int INL_reduce(nodeList*, int (*)(node*));

#endif
