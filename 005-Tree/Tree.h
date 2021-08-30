//
// Created by lindsey on 2021/8/20.
//

#ifndef DATASTRUCTURE_TREE_H


#include <iostream>
#include "../003-QueueAndStack/Queue.h"

using namespace std;

struct TreeNode {
    int data;
    TreeNode *right,*left;
};

TreeNode* findPosition(TreeNode *root,int data){
    TreeNode *temp = root;
    TreeNode *result;
    while(temp!= nullptr){
        result = temp;
        if(data > temp->data){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
    return result;
}

bool addNode(TreeNode *root,int data){
    TreeNode *child = (TreeNode*)malloc(sizeof(TreeNode));
    child -> data = data;
    child -> left = nullptr;
    child -> right = nullptr;
    TreeNode *node = findPosition(root,data);
    int rootData = node->data;
    if(data > rootData){
        node->left = child;
    }else{
        node->right = child;
    }
    return true;
}

void visite(TreeNode *node){
    cout << node->data;
}


void levelOrder(TreeNode *node){
    Queue<TreeNode*> *queue = new Queue<TreeNode*>;
    queue->push(node);
    while(!queue->isEmpty()){
        TreeNode *node = queue->pop();
        queue->push(node->right);
        queue->push(node->left);
        visite(node);
    }
}



void preOrder(TreeNode *node){
    if(node != nullptr){
        visite(node);
        preOrder(node->right);
        preOrder(node->left);
    }
}

void middleOrder(TreeNode *node){
    if(node != nullptr){
        preOrder(node->right);
        visite(node);
        preOrder(node->left);
    }
}

void postOrder(TreeNode *node){
    if(node != nullptr){
        preOrder(node->right);
        preOrder(node->left);
        visite(node);
    }
}

void print(TreeNode *root){
    if(root != nullptr){
        preOrder(root);
    }
}

#define DATASTRUCTURE_TREE_H

#endif //DATASTRUCTURE_TREE_H









