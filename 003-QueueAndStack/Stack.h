//
// Created by lindsey on 2021/8/21.
//

#ifndef DATASTRUCTURE_STACK_H
#include <iostream>
using namespace std;
template <typename T>
struct SNode {
    T data;
    SNode<T> *next;
};

template <typename T>
class Stack {
private:

    SNode<T> *head;

public:
    int lenght;
    Stack();
    ~Stack();
    void push(T data);
    T pop();
    bool isEmpty();
    T top();
};

template <typename T>
T Stack<T>::top() {
    return head->data;
}


template <typename T> Stack<T>::Stack() {
    lenght = 0;
    SNode<T> *node = (SNode<T>*)malloc(sizeof(SNode<T>));
    node->next = nullptr;
    head = node;
}

/**
 * 头插法
 * @tparam T
 * @param data
 */
template <typename T> void Stack<T>::push(T data) {
    SNode<T> *node = (SNode<T>*)malloc(sizeof(SNode<T>));
    node->data = data;
    node->next = head;
    head = node;
    lenght++;
}

template <typename T> T Stack<T>::pop() {
    if(isEmpty()){
        return 0;
    }
    T data = head->data;
    SNode<T> *node = head;
    head = head->next;
    free(node);
    lenght--;
    return data;
}

template <typename T> bool Stack<T>::isEmpty() {
    return lenght == 0;
}

#define DATASTRUCTURE_STACK_H

#endif //DATASTRUCTURE_STACK_H
