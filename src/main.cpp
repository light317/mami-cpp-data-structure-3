#include <iostream>
#include "FileReader.hpp"
#include <windows.h>

int main(){

    FileReader* fileReader = new FileReader("numbers.txt");
    TreeList* data = fileReader->GetTreeList();
    int sleepDuration = 10;

    BST* t;
    for(int i = 0; i<data->GetSize();i++){
        t = data->GetTreeAtIndex(i);
        t->PrintPostOrder(t->root);       
        std::cout<<"\n";
        Sleep(sleepDuration);
    }
}