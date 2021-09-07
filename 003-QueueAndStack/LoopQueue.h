//
// Created by lindsey on 2021/9/1.
//

#ifndef DATASTRUCTURE_LOOPQUEUE_H


template <typename T, int N>
class LoopQueue {
private:
    T data[N];
    int rear;
    int front;
public:
    LoopQueue<T,N>();
    ~LoopQueue<T,N>();
    void enqueue(T data);
    T dequeue();
    int len();
    void print();
};

template <typename T,int N>
int LoopQueue<T,N>::len(){
    return (rear - front) / N;
}

template <typename T,int N>
void LoopQueue<T,N>::print(){
    int len = 0;
    while(len < N){
        cout << data[len++] << "--";
    }
    cout << endl;
}



template <typename T,int N>
LoopQueue<T,N>::LoopQueue(){
    this->rear = 0;
    this->front = 0;
    for(int i = 0; i < N; i++){
        data[i] == -1;
    }
}

/**
 * initial:
 *          data[0] front rear
 *          len = 0
 * enqueue 1
 *          data[0] front
 *          data[1] rear
 *          len = 1
 * @tparam T
 * @tparam N
 * @param data
 */
template <typename T,int N>
void LoopQueue<T,N>::enqueue(T data){
    if( (rear + 1) % N == front){
        cout << "Full" << endl;
        return;
    }
    this->data[rear] = data;
    rear = (rear+1) % N;
}

template<typename T, int N>
T LoopQueue<T, N>::dequeue() {
    if(front == rear){
        cout << "Empty" << endl;
        return -1;
    }
    T data = this->data[front];
    front = (front+1) % N;
    return data;
}

template<typename T, int N>
LoopQueue<T, N>::~LoopQueue<T, N>() {

}

#define DATASTRUCTURE_LOOPQUEUE_H
#endif //DATASTRUCTURE_LOOPQUEUE_H
