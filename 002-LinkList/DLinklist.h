//
// Created by lindsey on 2021/8/5.
//

#ifndef DATASTRUCTURE_DLINKLIST_H


#include <iostream>
#include "../List.h"
using namespace std;

template <typename T>
struct DNode{
    T data;
    struct DNode *prior,*next;
};

template <typename T>
class Linklist : public List<T>{
private:
    DNode<T> *head;
    DNode<T> *tail;
    int size;
public:
    Linklist();
    bool insertLast(DNode<T> *p);
    bool insertFirst(DNode<T> *p);
    bool removeLast();
    void reverse();
    void foreach();
    DNode<T>* last();
private:
    DNode<T>* reverse(DNode<T> *p);
};

template <typename T>
DNode<T>* Linklist<T>::last() {
    return tail;
}

template <typename T>
void Linklist<T>::reverse(){
    DNode<T> *curr = head->next;
    tail = curr;
    DNode<T> *new_head = reverse(curr);
    head->next = new_head;
}

template <typename T>
DNode<T>* Linklist<T>::reverse(DNode<T> *p) {
    if (p->next == nullptr) {
        return p;
    }
    DNode<T> *last = reverse(p->next);
    p->next->prior = p->next->next;
    p->next->next = p;
    p->next = nullptr;
    return last;
}

template <typename T>
bool Linklist<T>::removeLast(){
    if(tail == nullptr){
        return false;
    }
    tail->prior->next = nullptr;
    tail = tail->prior;
    return true;
}

template <typename T>
void Linklist<T>::foreach() {
    DNode<T> *dummy = this->head;
    while(dummy->next != nullptr){
        cout << dummy->next->data;
        dummy = dummy->next;
    }
    cout << endl;
}

template <typename T>
Linklist<T>::Linklist(){
    // 初始化头节点
    this->head = (DNode<T> *)malloc(sizeof(DNode<T>));
    this->head->data = -1;
    this->head->next = tail;
    this->head->prior = nullptr;
    tail = nullptr;
    this->size = 0;
}

template <typename T>
bool Linklist<T>::insertLast(DNode<T> *p) {
    if(tail == nullptr){
        tail = p;
        head->next = p;
        tail->prior = head;
    }else{
        tail->next = p;
        p->prior = tail;
        tail = p;
    }
    size++;
    return true;
}

template <typename T>
bool Linklist<T>::insertFirst(DNode<T> *p) {
    p->next = head->next;
    head->next->prior = p;
    head->next = p;
    p->prior = head;
    size++;
    return true;
}
#define DATASTRUCTURE_DLINKLIST_H
#endif //DATASTRUCTURE_DLINKLIST_H
