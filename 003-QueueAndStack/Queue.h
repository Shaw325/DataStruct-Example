//
// Created by lindsey on 2021/8/20.
//

#ifndef DATASTRUCTURE_QUEUE_H

template <typename T>
struct QNode{
    T data;
    QNode<T> *prev,*next;
};

template <typename T>
class Queue {
private:
    int lenght;
    QNode<T> *head;
    QNode<T> *last;
public:
    Queue();
    ~Queue();
    void push(T data);
    T pop();
    bool isEmpty();
};

template <typename T> Queue<T>::~Queue() {
    cout << "我被释放了" <<endl;
}

template <typename T> Queue<T>::Queue() {
    QNode<T> *dummy = (QNode<T>*)malloc(sizeof(QNode<T>));
    dummy->next = nullptr;
    head = dummy;
    last = dummy;
    head->next = last;
    last->prev = head;
    lenght = 0;
}

template <typename T> void Queue<T>::push(T data) {
    if(data == NULL){
        return;
    }
    QNode<T> *node = (QNode<T>*)malloc(sizeof(QNode<T>));
    node->data = data;
    node->next = nullptr;
    if(lenght == 0){
        node->prev = head;
        head->next = node;
    }else{
        node->prev = last;
        last->next = node;
    }
    last = node;
    lenght++;
}

template <typename T>
T Queue<T>::pop() {
    if(isEmpty()){
        return NULL;
    }
    lenght--;
    QNode<T> *node = head->next;
    if(node->next){
        node->next->prev = head;
    }
    head->next = node->next;
    return node->data;
}

template <typename T>
bool Queue<T>::isEmpty() {
    return lenght == 0;
}

#define DATASTRUCTURE_QUEUE_H
#endif //DATASTRUCTURE_QUEUE_H