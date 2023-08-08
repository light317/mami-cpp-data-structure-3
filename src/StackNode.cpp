#include "StackNode.hpp"

StackNode::StackNode(int val){
    Value = val;
    Prev = nullptr;
}

int StackNode::GetValue(){
    return Value;
}

StackNode* StackNode::GetPrev(){
    return Prev;
}

void StackNode::SetPrevNode(StackNode* node){
    Prev = node;
}