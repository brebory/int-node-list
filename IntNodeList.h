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

typedef struct IntNode {
    int element;
    struct IntNode* prev;
}
IntNode;

typedef struct {
    IntNode* top;
}
IntNodeList;

IntNodeList* createIntNodeList(int);

IntNode* createIntNode(int);

IntNodeList* INL_clone(IntNodeList*);

void INL_push(IntNodeList*, int);

int INL_pop(IntNodeList*);

bool INL_search(IntNodeList*, int);

IntNodeList* INL_filter_(IntNodeList*, bool (*)(IntNode*));

IntNodeList* INL_filter(IntNodeList*, bool (*)(IntNode*));

IntNodeList* INL_map_(IntNodeList*, int (*)(int));

IntNodeList* INL_map(IntNodeList*, int (*)(int));

int INL_reduce(IntNodeList*, int (*)(IntNode*));

#endif
