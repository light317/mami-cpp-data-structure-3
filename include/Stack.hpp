#ifndef STACK_HPP
#define STACK_HPP

#include "StackNode.hpp"

class Stack{
    private:
        int StackSize;
        StackNode* Head;
        StackNode* Tail;

    public:
        Stack(int value);
        void Push(int value);
        int Peek();
        int Pop();
        int Size();
        void Print();
};


#endif