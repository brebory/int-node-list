//
//  main.c
//  IntNodeListUnitTests
//
//  Created by Brendon Roberto on 2/14/13.
//  Copyright (c) 2013 Brendon Roberto. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <mach/mach_time.h>
#include <CoreFoundation/CfDate.h>
#include "IntNodeList.h"

#define SIZE 5

void testFixture(FILE* fp, bool correct, uint64_t id, const char *testName) {
    if (correct) {
        fprintf(fp, "testid: %lld> Results of testing %s: %s works as expected.\n", id, testName, testName);
    } else {
        fprintf(fp, "testid: %lld> Results of testing %s: %s has errors.\n", id, testName, testName);
    }
}

int multiply_by_5(int number) {
    return number * 5;
}


int main(int argc, const char * argv[])
{
    IntNodeList* list;
    IntNodeList* list2;
    int buff[SIZE];
    int pop_results[SIZE];
    int clone_results1[SIZE];
    int clone_results2[SIZE];
    int map_results1[SIZE];
    int map_results2[SIZE];
    int i;
    bool correct = true;
    uint64_t testID = mach_absolute_time();
    
    FILE* fp = fopen("log", "a");
    if (fp == NULL)
        return -1;

    for (i = 0; i < SIZE; i++) {
        buff[i] = i * 10;
        list = createIntNodeList(buff[i]);
        if (list->top->element != buff[i])
            correct = false;
    }
    
    testFixture(fp, correct, testID, "IntNodeList");
    
    correct = true;
    
    list = createIntNodeList(buff[0]);
    for (i = 1; i < SIZE; i++) {
        INL_push(list, buff[i]);
        if (list->top->element != buff[i])
            correct = false;
    }    
    
    testFixture(fp, correct, testID, "INL_push");
    
    correct = true;
    
    for (i = 0; i < SIZE; i++) {
        pop_results[i] = INL_pop(list);
        if (pop_results[i] != buff[SIZE - (i + 1)])
            correct = false;
    }
    
    testFixture(fp, correct, testID, "INL_pop");
    
    correct = true;
    
    list = createIntNodeList(buff[0]);
    for (i = 1; i < SIZE; i++)
        INL_push(list, buff[i]);
    
    list2 = INL_clone(list);
    
    for (i = 0; i < SIZE; i++) {
        clone_results1[i] = INL_pop(list);
        clone_results2[i] = INL_pop(list2);
        if(clone_results1[i] != clone_results2[i])
            correct = false;
    }
    
    testFixture(fp, correct, testID, "INL_clone");
    
    correct = true;
    
    list = createIntNodeList(buff[0]);
    for (i = 1; i < SIZE; i++)
        INL_push(list, buff[i]);
    
    list = INL_map_(list, multiply_by_5);
    
    for (i = 0; i < SIZE; i++) {
        map_results1[i] = INL_pop(list);
        map_results2[i] = i * 50;
        if (map_results1[i] != map_results2[i])
            correct = false;
    }
    
    testFixture(fp, correct, testID, "INL_map_");
    
    fclose(fp);
}

