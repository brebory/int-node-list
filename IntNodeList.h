//
//  list.h
//  lists
//
//  Created by Brendon Roberto on 2/14/13.
//  Copyright (c) 2013 Brendon Roberto. All rights reserved.
//

#ifndef intnodelist_h
#define intnodelist_h

typedef struct node{
    int element; // data within list
    struct node* next; // pointer to next node
    struct node* prev; // pointer to previous node
}
node;

node* NodeList(int);

void NL_push(node*, int);

int NL_pop(node*);

node* NL_traverse(node*);

#endif
