#include <iostream>

#include "002-LinkList/DLinklist.h"
#include "004-String/String.h"
#include "005-Tree/Tree.h"
#include "003-QueueAndStack/Queue.h"
#include "003-QueueAndStack/Stack.h"

using namespace std;


int strlen(char *h) {
    int len = 0;
    char v = *(h);
    while (v != '\0') {
        v = *(h + ++len);
    }
    return len;
}


TreeNode *create(int data) {
    TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));
    root->data = data;
    root->right = nullptr;
    root->left = nullptr;
    return root;
}

int main() {
    //----------------------------LinkList Test ---------------------------------
//    Linklist<int> l;
//    DNode<int> n = {1, nullptr, nullptr};
//    l.insertLast(&n);
//    l.foreach();
//    DNode<int> n2 = {2, nullptr, nullptr};
//    DNode<int> n3 = {3, nullptr, nullptr};
//    l.insertFirst(&n2);
//    l.insertLast(&n3);
//
//    // each every node and print it
//    l.foreach();
//    // reverse all node in the linklist
//    l.reverse();
//    // reverse again all node in the linklist
//    l.foreach();
//    // appending one node in the last in the linklist
//    DNode<int>* last = l.last();
//    cout << (last->data) << endl;

    //----------------------------String Test ---------------------------------
    char *h=(char*)"Hello";
    cout << strlen(h) << endl;
    String str = String((char *) "abc");
    String str1 = String((char *) "a");
    String str2 = String((char *) "abc");
    int compara = String::compare(&str, &str1);
    cout << boolalpha;
    cout << (str == str2) << endl;
    cout << str.len() << endl;
    cout << str1.len() << endl;
    cout << compara << endl;
    cout << (str + str1).len() << endl;
    String *mainStr = new String((char*)"Do you know that Google is the best company in the world.");
    String *matchStr = new String((char*)"Google");
    // using kmp method to recursive the index of the substring
    int index = mainStr->kmp(matchStr);
    cout << "Main String : ["
    << *(mainStr) << "]\r\n"
            << "Match String: ["
            << *(matchStr) << "]\r\n"
            << "Match position :" << index << endl;


    //----------------------------Tree Test ---------------------------------
//    TreeNode *root = create(5);
//    TreeNode *dummy = root;
//    for (int i = 0; i < 5; ++i) {
//        addNode(dummy,i);
//    }
//    for (int i = 6; i < 10; ++i) {
//        addNode(dummy,i);
//    }
//    cout << "Pre order iteration:" << endl;
//    preOrder(root);
//    cout << endl;
//    /**
//     *              5
//     *   01234-0         6789-6
//     * --     1234-1      ---     789-7
//     *
//     */
//    cout << "Middle order iteration:" << endl;
//    middleOrder(root);
//    cout << endl;
//    cout << "Post order iteration:" << endl;
//    postOrder(root);
//    cout << endl;
//    cout << "Level order iteration:" << endl;
//    levelOrder(root);
//    cout << endl;


    //----------------------------Queue Test ---------------------------------
//    Queue<int> *queue = new Queue<int>;
//    queue->push(2);
//    queue->push(3);
//    queue->push(4);
//
//    cout << queue->pop() << endl;
//    cout << queue->pop() << endl;
//    cout << queue->pop() << endl;


    //----------------------------Stack Test ---------------------------------
//    Stack<int> *stack = new Stack<int>();
//    stack->push(2);
//    stack->push(3);
//    stack->push(4);
//    cout << stack->pop() << endl;
//    cout << stack->pop() << endl;
//    cout << stack->pop() << endl;

//    return 0;
}




