//
// Created by lindsey on 2021/8/26.
//

#ifndef DATASTRUCTURE_LINKLIST_H
#define DATASTRUCTURE_LINKLIST_H


template<typename T>
struct Node {
    T item;
    Node *next,*prev;
};

template<T typename>
class LinkList {
private:
    Node<T> *first,*last;
    int length;
public:
    LinkList();
    ~LinkList();
};

#endif //DATASTRUCTURE_LINKLIST_H
