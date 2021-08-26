//
// Created by lindsey on 2021/8/21.
//

#ifndef DATASTRUCTURE_STACK_H

template <typename T>
struct SNode {
    T data;
    SNode<T> *prev,*next;
};

template <typename T>
class Stack {
private:
    int lenght;
    SNode<T> *last;

public:
    Stack();
    ~Stack();
    void push(T data);
    T pop();
    bool isEmpty();
};


template <typename T> Stack<T>::Stack() {
    lenght = 0;
    SNode<T> *node = (SNode<T>*)malloc(sizeof(SNode<T>));
    node->data = -1;
    node->next = nullptr;
    node->prev = nullptr;
    last = node;
}

template <typename T> void Stack<T>::push(T data) {
    SNode<T> *node = (SNode<T>*)malloc(sizeof(SNode<T>));
    node->data = data;
    node->next = nullptr;
    node->prev = last;
    last->next = node;
    last = node;
    lenght++;
}

template <typename T> T Stack<T>::pop() {
    if(isEmpty()){
        return NULL;
    }
    SNode<T> *node = last;
    last->prev->next = nullptr;
    last = last->prev;
    return node->data;
}

template <typename T> bool Stack<T>::isEmpty() {
    return last->data == -1;
}

#define DATASTRUCTURE_STACK_H

#endif //DATASTRUCTURE_STACK_H
