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
    void printLevel();
};


void AVLTree::printLevel(){
    if(empty()){
        cout << "空" << endl;
    }
    Queue<int> *fill_q = new Queue<int>();
    Queue<TreeNode*> *queue = new Queue<TreeNode*>();
    queue->push(root);
    while(!queue->isEmpty()){
        TreeNode *node = queue->pop();
        if(node->data != -1 && node->left == nullptr){
            queue->push(createNode(-1));
        }else{
            queue->push(node->left);
        }
        if(node->data != -1 && node->right == nullptr){
            queue->push(createNode(-1));
        }else{
            queue->push(node->right);
        }
        
        int height = node->height;
        // 最底层需要填充数量
        if((node->parent!=nullptr&&node->parent->left == node) || node == this->root){
            int fill = (height-1)*2-1;
            for(int i =0;i<fill;i++){
                fill_q->push(-1);
            }
        }
        if((node->parent!=nullptr&&node->parent->right == node)){
            int fill2 = height *2 -1;
            for(int i =0;i<fill2;i++){
                fill_q->push(-1);
            }
        }
        if(node->data == -1){
            fill_q->push(-1);
        }
        fill_q->push(node->data);
         TreeNode *next = queue->get();
        if(next!=nullptr && next->height != node->height){
            fill_q->push(-2);
        }
        
       
        // if(next!=nullptr && next->height != node->height){
        //     fill_q->push(-2);
        // }
    }
    while(!fill_q->isEmpty()){
        int mark = fill_q->pop();
        if(mark == -1){
            cout << " ";
        }else if(mark == -2){
            cout << "" << endl;
        }else{
            cout << mark;
        }
    }
}

AVLTree::AVLTree(){
    root = nullptr;
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
        if(abs(bf(move)) == 2){
            // 从这个结点开始平衡
            balance(move);
            break;
        }
        move = move -> parent;
    }
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

// void AVLTree::adjustBf(TreeNode *x){
//     // 已经到了顶端
//     if(x->parent == nullptr){
//         return;
//     }
//     TreeNode *p = x->parent;
//     int bf = x->bf;
//     /*
//      * 平衡因子(bf)的绝对值当小于2时，分三种情况
//      * 1. (bf)大于0的情况下,调整祖先结点的平衡因子，递归到根或者平衡因子大于2为止
//      * 2. (bf)小于0的情况，调整祖先结点的平衡因子，递归到根或者平衡因子小于-2为止
//      * 3. (bf)等于0的情况，树不需要调整平衡因子，即对于祖先结点来说，子树高
//      * 度并无变化，直接跳出
//      *
//      */
//     if(abs(bf) < 2){
//         if(bf == 0){
//             return;
//         }
//         if(bf > 0){
//             p->bf++;
//         }else if(bf < 0){
//             p->bf--;
//         }
//         adjustBf(p);
//     }else {
//         if(bf == -2){//需要左旋，为负数说明右结点大于左结点
            
//         }else if(bf == 2){// 需要右旋，为正2代表左结点大于右结点
//             right_rotate(x);
//         }
//     }
   
// }

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



