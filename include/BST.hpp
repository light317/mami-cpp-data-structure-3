// The binary search tree

#ifndef BST_HPP
#define BST_HPP

#include "BSTNode.hpp"

class BST{
    private:
        int max(int,int);
        BSTNode* MinValueNode(BSTNode*);

    public:
        BSTNode* root;
        BST();
        BST(BSTNode*);
        int GetHeight(BSTNode*);
        int GetHeight();
        // BSTNode* NewNode(int);
        BSTNode* DeleteNode(BSTNode*,int);
        BSTNode* InsertNode(BSTNode*,int);
        bool IsBalanced(BSTNode*);
        void PrintInOrder(BSTNode* root);
        void PrintPostOrder();
        void PrintPostOrder(BSTNode* root);
        int GetSumOfNodeValues();
        int GetSumOfNodeValues(BSTNode* root);
        BSTNode* Clone();
        BSTNode* Clone(BSTNode* root);



};


#endif