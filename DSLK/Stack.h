#ifndef _STACK_H_
#define _STACK_H_

#include "SList.h"
// Các thao tác trên Stack

template <class T>
void initStack(SList<T> &stack) {
    initSList(stack);
}

template <class T>
bool isEmptyStack(SList<T> stack) {
    return isEmptySList(stack);
}

template <class T>
void push(SList<T> &stack, T x) {
    addHeadSList(stack, x);
}

template <class T>
T pop(SList<T> &stack) {
    T x = stack.head->info;
    deleteHeadSList(stack);
    return x;
}

template <class T>
T top(SList<T> stack) {
    return stack.head->info;
}

#endif

