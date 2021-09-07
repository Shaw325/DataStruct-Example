//
// Created by lindsey on 2021/9/2.
//

#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node *next;
};

template <typename T>
Node<T> *create(T data){
    Node<T> *head = (Node<T>*)malloc(sizeof(Node<T>));
    head->data = data;
    head->next = nullptr;
    return head;
}

Node<int> *mergerTwo(Node<int>* la,Node<int>* lb){
    Node<int> *lc = create(-1);
    Node<int> *dummy = lc;
    while(la != nullptr && lb != nullptr){
        if(la->data < lb->data){
            lc->next = la;
            lc = lc->next;
            la = la->next;
        }else{
            lc->next = lb;
            lc = lc->next;
            lb = lb->next;
        }
    }
    if(la != nullptr) lc->next = la;
    if(lb != nullptr) lc->next = lb;
    return dummy->next;
}


int main(){
    Node<int> *head = create(0);
    Node<int> *node1 = create(1);
    Node<int> *node2 = create(4);
    Node<int> *node3 = create(5);
    Node<int> *node4 = create(6);
    Node<int> *node5 = create(9);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    Node<int> *head2 = create(2);
    Node<int> *node11 = create(3);
    Node<int> *node22 = create(5);
    Node<int> *node33 = create(7);
    Node<int> *node44 = create(10);
    Node<int> *node55 = create(11);
    head2->next = node11;
    node11->next = node22;
    node22->next = node33;
    node33->next = node44;
    node44->next = node55;

    Node<int> *lc = mergerTwo(head,head2);
    while(lc != nullptr){
        cout << lc->data << endl;
        lc = lc->next;
    }

};
