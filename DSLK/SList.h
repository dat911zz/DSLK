#ifndef _SLIST_H_
#define _SLIST_H_

#include <iostream>
using namespace std;

template <class T>
struct Node {
    T info;
    Node<T> * next;
};

template <class T>
struct SList {
    Node<T> *head;
    Node<T> *tail;
};

template <class T>
void initSList(SList<T> &list) {
    list.head = list.tail = NULL;
}

template <class T>
Node<T> *createNode(T x) {
    Node<T> *p = new Node<T>;
    if (p != NULL)
    {
        p->info = x;
        p->next = NULL;
    }
    return p;
}

template <class T>
void deleteNode(Node<T> * &p) {
    if(p == NULL)
        return;
    delete p;
}

template <class T>
bool isEmptySList(SList<T> list) {
    return list.head == NULL;
}

template <class T>
Node<T> * searchSList(SList<T> list, T x) {
    Node<T> *p;
    p = list.head;
    while(p != NULL)
    {
        if(p->info == x)
            return p;
        p = p->next;
    }
    return NULL;
}

template <class T>
void addHeadSList(SList<T> &list, Node<T> * p) {
    if(p == NULL)
        return;
    if(list.head == NULL) //danh sách rỗng
        list.head = list.tail = p;
    else
    {
        p->next = list.head;
        list.head = p;
    }
}

template <class T>
void addHeadSList(SList<T> &list, T x) {
    Node<T> * p = createNode(x);
    addHeadSList(list, p);
}

template <class T>
void addTailSList(SList<T> &list, Node<T> * p) {
    if(p == NULL)
        return;
    if(list.head == NULL)
        list.head = list.tail = p;
    else
    {
        list.tail->next = p;
        list.tail = p;
    }
}

template <class T>
void addTailSList(SList<T> &list, T x) {
    Node<T> * p = createNode(x);
    addTailSList(list, p);
}

template <class T>
void addAfterNodeSList(SList<T> &list, Node<T> * q, Node<T> * p) {
    if(p == NULL || q == NULL)
        return;
    if(list.head == NULL)
        list.head = list.tail = p;
    else
    if(q == list.tail)
        addTailSList(list,p);
    else
    {
        p->next = q->next;
        q->next = p;
    }
}

template <class T>
void addAfterNodeSList(SList<T> &list, Node<T> * q, T x) {
    Node<T> * p = createNode(x);
    addAfterNodeSList(list, p, q);
}

template <class T>
void deleteHeadSList(SList<T> &list) {
    if(list.head==NULL)
        return ;
    Node<T> * p=list.head;
    list.head = p->next;
    p->next = NULL;
    if (list.head == NULL)
        list.tail = NULL;
    delete p;
}

template <class T>
void deleteTailList (SList<T> &list) {
    if(list.head == NULL)
        return;
    if (list.head->next == NULL) {
        list.head = list.tail = NULL;
        return;
    }
    Node<T> * p = list.tail;
    //tim node nam ngay truoc tail
    Node<T> *q = list.head;
    while(q->next != list.tail)
        q = q->next;
    //cắt node tail rồi list và xóa
    list.tail = q;
    list.tail->next = NULL;
    delete p;
}

template <class T>
void deleteMidList (SList<T> &list, Node<T> * q) {
    if(list.head == NULL || q == NULL || q == list.tail)
        return ;
    if(q->next == list.tail)
        deleteTailList(list);
    else
    {
        Node<T> * p = q->next;
        q->next = p->next;
        p->next = NULL;
        delete p;
    }
}

template <class T>
void interchangeSortSList (SList<T> list) {
    for(Node<T> * p = list.head; p != list.tail; p = p->next)
        for(Node<T> * q = p->next; q != NULL; q = q->next)
            if(p->info > q->info)
                swap(p->info, q->info);
}

#endif
