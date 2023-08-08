#include "TreeList.hpp"
#include <iostream>

TreeList::TreeList(int size){
    Trees = new BST*[size];
    ListSize = size;
}

void TreeList::SetTreeAtIndex(int index, BST* tree){
    if(index > ListSize - 1)
        std::cout<<"Invalid index.\n";

    Trees[index] = tree;
}

BST* TreeList::GetTreeAtIndex(int index){
    if(index > ListSize - 1)
       std::cout<<"Invalid index.\n";

    return Trees[index];
}

int TreeList::GetSize(){
    return ListSize;
}

// TreeList::~TreeList(){
//     delete [] Trees;
// }