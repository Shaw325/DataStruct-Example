//
// Created by lindsey on 2021/8/20.
//

#ifndef DATASTRUCTURE_QUEUE_H

/**
 * 队列
 * 链式结构实现
 * 单向链表实现
 * 入队移动rear指针
 * 出队移动front指针
 *
 * @tparam T
 */
template <typename T>
struct QNode{
    T data;
    QNode<T> *next;
};

template <typename T>
class Queue {
private:
    int lenght;
    QNode<T> *front;
    QNode<T> *rear;
public:
    Queue();
    ~Queue();
    void push(T data);
    T pop();
    T get();
    T last();
    bool isEmpty();
};

template <typename T> Queue<T>::~Queue() {
    std::cout << "我被释放了" <<std::endl;
}

template <typename T> Queue<T>::Queue() {
    QNode<T> *node = (QNode<T>*)malloc(sizeof(QNode<T>));
    node->next = nullptr;
    front = node;
    rear = node;
    front->next = rear;
    lenght = 0;
}

template <typename T> void Queue<T>::push(T data) {
    if(!data){
        return;
    }
    QNode<T> *node = (QNode<T>*)malloc(sizeof(QNode<T>));
    node->data = data;
    node->next = nullptr;
    rear->next = node;
    rear = node;
    lenght++;
}

template <typename T>
T Queue<T>::last() {
    if(isEmpty()){
        return 0;
    }
    T data = rear->data;
    return data;
}

template <typename T>
T Queue<T>::pop() {
    if(isEmpty()){
        return 0;
    }
    lenght--;
    T data = front->next->data;
    QNode<T> *node = front;
    front = front->next;
    free(node);
    return data;
}

template <typename T>
T Queue<T>::get() {
    if(isEmpty()){
        return 0;
    }
    T data = front->next->data;
    return data;
}

template <typename T>
bool Queue<T>::isEmpty() {
    return lenght == 0;
}

#define DATASTRUCTURE_QUEUE_H
#endif //DATASTRUCTURE_QUEUE_H