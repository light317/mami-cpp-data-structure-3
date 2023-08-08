#ifndef STACKNODE_HPP
#define STCKNODE_HPP

class StackNode{
    private:
        int Value;
        StackNode* Prev;

    public:
        StackNode(int val);
        void SetPrevNode(StackNode* node);
        StackNode* GetPrev();
        int GetValue();
};

#endif