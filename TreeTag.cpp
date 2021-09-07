//
// Created by lindsey on 2021/9/2.
//
#include <stdlib.h>
struct TreeNode {
    int data;
    int tag;
    TreeNode *right,*left;
};


TreeNode *create(int count){
    if(count >= 100){
        return nullptr;
    }
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode*));
    node->data = count;
    node->tag = count+9;
    node->right = create(count*2);
    node->left = create(count*2+1);
    return node;
}

TreeNode *find(TreeNode *root,int data){
    if(root == nullptr){
        return nullptr;
    }
    if(root->tag == data){
        return root;
    }
    TreeNode *right = find(root->right,data);
    TreeNode *left = find(root->left,data);
    return right == nullptr ? left : right;
}

int main() {
    TreeNode *root = create(1);
    TreeNode *next = find(root,49);
    return 0;
}