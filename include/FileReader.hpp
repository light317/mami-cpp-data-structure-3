#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "TreeList.hpp"
#include "Stack.hpp"

class FileReader{
    private:
        TreeList* Data;
        std::string FilePath;
        BST* GetTreeToBeSaved(BST* firstTree, BST* secondTree);
    public:
        FileReader(std::string path);
        void ReadFile();
        TreeList* GetTreeList();
        int LineCount();
        ~FileReader();
};

#endif