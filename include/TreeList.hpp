#ifndef TREELIST_HPP
#define TREELIST_HPP

#include "BST.hpp"

class TreeList{
    private:
        BST** Trees;
        int ListSize;
    public:
        TreeList(int size);
        // ~TreeList();
        void SetTreeAtIndex(int index, BST* tree);
        BST* GetTreeAtIndex(int index);
        int GetSize();

};

#endif
