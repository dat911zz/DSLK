#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "SList.h"

// Các thao tác trên hàng đợi
template <class T>
void initQueue(SList<T> &queue) {
    initSList(queue);
}

template <class T>
bool isEmptyQueue(SList<T> queue) {
    return isEmptySList(queue);
}

template <class T>
void enqueue(SList<T> &queue,T x) {
    addTailSList(queue, x);
}

template <class T>
T dequeue(SList<T> &queue) {
    T x = queue.head->info;
    deleteHeadSList(queue);
    return x;
}

template <class T>
T  getHead(SList<T> queue) {
    return  queue.head->info;
}

template <class T>
T  getTail(SList<T> queue) {
    return  queue.tail->info;
}

#endif