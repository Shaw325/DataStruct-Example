//
// Created by lindsey on 2021/8/21.
//
#ifndef DATASTRUCTURE_BALANCETREE_H
#define DATASTRUCTURE_BALANCETREE_H
#include <iostream>
#include "../003-QueueAndStack/Queue.h"
using namespace std;
#define OFFSET 0x7fffff
int abs(int x){
    return x & OFFSET;
}


/**
 *  自平衡二叉树 
 * 
 * bf：平衡因子，由left.bf-right.bf
 * 正常情况下只能为-1，0，1
 * 当-2>=bf>=2时，需要触发平衡操作
 *
 */
#define LB 1;
#define RB -1;
#define BL 0;

struct TreeNode {
    int data;
    int height;
    TreeNode *left,*right,*parent;
};

class AVLTree {
private:
    
    int size;
    TreeNode *createNode(int data);
    void balance(TreeNode *node);
    int node_height(TreeNode *node);
    int bf(TreeNode *node);
    void adjustHeight(TreeNode *node);
    void post(TreeNode *node);
public:
TreeNode *root;
    AVLTree();
    ~AVLTree();
    void insert(int data);
    void remove(int data);
    void rotate_L(TreeNode *node);
    void rotate_R(TreeNode *node);
    void rotate_LR(TreeNode *node);
    void rotate_RL(TreeNode *node);
    bool empty();
    void postorder();
};


AVLTree::AVLTree(){
    root = nullptr;
}

AVLTree::~AVLTree(){
    
}

void AVLTree::postorder(){
    this->post(this->root);
    cout << endl;
}

void AVLTree::post(TreeNode *node){
    if(node == nullptr){
        return;
    }
    post(node->left);
    post(node->right);
    cout << node->data;
}

TreeNode* AVLTree::createNode(int data){
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;
    node->height = 1;
    return node;
}

bool AVLTree::empty(){
    return this->root==nullptr;
}

int AVLTree::bf(TreeNode *node){
    int lh = node_height(node->left);
    int rh = node_height(node->right);
    return lh-rh;
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
    /**
     * 调节平衡因子
     * 
     * 插入左子树时，bf+1
     * 插入右子树时，bf-1
     * 
     * 1. 插入结点的BF从1调至0时，不需要更改祖先结点的平衡因子，只要更改当前的平衡因子
     * 2. 插入结点的BF从0调至1、-1时，需要更改祖先结点的平衡因子，直到根结点
     */
    if(x->data > data){ // 插入左边
        x->left = node;        
    }else{ // 插入右边
        x->right = node;
    }
    node->parent = x;
    // 回溯回第一个结点触发旋转的结点，逐个更新height
    TreeNode *move = x;
    while(move !=nullptr){
        int lh = node_height(move->left);
        int rh = node_height(move->right);
        move->height = max(lh,rh) + 1;
        if(bf(move) == 2 || bf(move) == -2){
            // 从这个结点开始平衡
            this->postorder();
            balance(move);
            this->postorder();
            break;
        }
        move = move -> parent;
    }
    this->size++;
}



void AVLTree::balance(TreeNode *node){
    TreeNode *left = node->left;
    TreeNode *right = node->right;
    int lh = node_height(left);
    int rh = node_height(right);
    if(lh > rh && left != nullptr){// 左边比右边高
        if(left->left !=nullptr){
            rotate_R(node);
        }else{
            rotate_LR(node); 
        }
    }else if(lh < rh && right != nullptr){
        if(right->right != nullptr){
            rotate_L(node);
        }else{
            rotate_RL(node);
        }
    }
}

int AVLTree::node_height(TreeNode *node){
    if(node == nullptr){
        return 0;
    }
    return node->height;
}


void AVLTree::rotate_LR(TreeNode *node){
    TreeNode *left = node->left;
    rotate_L(left);
    rotate_R(node);
}

void AVLTree::rotate_RL(TreeNode *node){
    TreeNode *right = node->right;
    rotate_L(right);
    rotate_R(node);
}


void AVLTree::rotate_L(TreeNode *node){
    TreeNode *p = node->parent;
    TreeNode *right = node->right;
    TreeNode *subL = right->left;
    node->right = subL;
    if(subL != nullptr){
        subL->parent = node;
    }
    right->left = node;
    if(p == nullptr){
        right->parent = this->root->parent;
        this->root = right;
    }else{
        if(p->left == node){
            p->left = right;
        }else if(p->right == node){
            p->right = right;
        }
        right->parent = p;
    }
    node->parent = right;
    adjustHeight(node);
    adjustHeight(right);
}

void AVLTree::rotate_R(TreeNode *node){
    TreeNode *p = node->parent;
    TreeNode *left = node->left;
    TreeNode *subR = left->right;
    node->left = subR;
    if(subR != nullptr){
        subR->parent = node;
    }
    left->right = node;
    if(p == nullptr){
        left->parent = this->root->parent;
        this->root = left;
    }else{
        if(p->left == node){
            p->left = left;
        }else if(p->right == node){
            p->right = left;
        }
        left->parent = p;
    }
    node->parent = left;
    adjustHeight(node);
    adjustHeight(left);
}

void AVLTree::adjustHeight(TreeNode *node){
    TreeNode *left = node->left;
    TreeNode *right = node->right;
    int lh = node_height(left);
    int rh = node_height(right);
    node->height = max(lh,rh) + 1;
}

#endif //DATASTRUCTURE_BALANCETREE_H



