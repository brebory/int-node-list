//
//  list.c
//  lists
//
//  Created by Brendon Roberto on 2/14/13.
//  Copyright (c) 2013 Brendon Roberto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "IntNodeList.h"

node* NodeList(int element) {
    node* node = malloc(sizeof(node));
    node->element = element;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void NL_push(node* list, int element) {
    node next = { element, NULL, list };
    list->next = &next;
}

int NL_pop(node* list) {
    list = NL_traverse(list);
    return NL_traverse(list)->element;
}

node* NL_traverse(node* list) {
    while (list->next != NULL) {
        list = list->next;
    }
    return list;
}