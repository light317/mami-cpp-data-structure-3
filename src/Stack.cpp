#include "Stack.hpp"
#include <iostream>

Stack::Stack(int value){
    Tail = new StackNode(value);
    Tail->SetPrevNode(nullptr);
    Head = Tail;
    StackSize = 1;
}

void Stack::Push(int value){
    StackNode* node = new StackNode(value);

    node->SetPrevNode(Head);
    Head = node;

    StackSize++;
}
int Stack::Peek(){
    // Just gets the value of the head
    if(StackSize == 0){
        std::cout<<"Stack is empty.\n";
        return -99999;
    }
    
    return Head->GetValue();
}
int Stack::Pop(){
    if(StackSize == 0){
        std::cout<<"Stack is empty.\n";
        return -99999;
    }

    int headValue = Peek();

    StackNode* tempNode = Head;
    Head = Head->GetPrev();

    StackSize--;
    delete tempNode;
    return headValue;
}

int Stack::Size(){
    return StackSize;
}

void Stack::Print(){
     for(StackNode* temp = this->Head; temp != nullptr; temp = temp->GetPrev())
     {
        std::cout<<temp->GetValue()<<"\n";
     }
     std::cout<<"\n";
}