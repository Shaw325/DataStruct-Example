//
// Created by lindsey on 2021/8/21.
//
#ifndef DATASTRUCTURE_BALANCETREE_H
#define DATASTRUCTURE_BALANCETREE_H
#include "Math.h"
/**
 *  自平衡二叉树 
 * 
 *
*/

struct TreeNode {
    int data;
    int lh,rh;
    TreeNode *left,*right,*parent;
}

class AVLTree {
private:
    TreeNode *root;
    int size;
    TreeNode *createNode(int data);
    void rotate(TreeNode *node);
public:
    AVLTree();
    ~AVLTree();
    void insert(int data);
    void remove(int data);
    void left_rotate(TreeNode *node);
    void right_rotate(TreeNode *node);
    bool empty();
}

AVLTree::AVLTree(){
    root = nullptr;
}

AVLTree::createNode(int data){
    TreeNode *node = (TreeNode*)mallow(sizeof(TreeNode));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;
    node->lh = 0;
    node->rh = 0;
    return node;
}

bool empty(){
    return this->root=nullptr;
}

void AVLTree::insert(int data){
    TreeNode *node = createNode(data);
    // 为空的时候直接当前结点设为根结点
    if(empty()){
        this->root = node;
        return;
    }
    // 找到插入结点,使用双指针法
    TreeNode *temp = this->root;
    TreeNode *x = nullptr;
    while(temp!=nullptr){
        x = temp;
        if(data > temp->data){
            temp = temp->right;
        }else{
            temp = temp->left;
        }
    }

    // 挂载结点
    if(data > x->data){
        x->right = node;
        x->rh = x->rh + 1;
    }else{
        x->left = node;
        x->lh = x->lh + 1;
    }
    rotate(x);
}

void AVLTree::rotate(TreeNode *x){
    
}

void AVLTree::left_rotate(TreeNode *node){
    
}

void AVLTree::right_rotate(TreeNode *node){
    
}

#endif //DATASTRUCTURE_BALANCETREE_H


