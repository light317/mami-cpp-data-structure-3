#include "FileReader.hpp"

FileReader::FileReader(std::string path){
    FilePath = path;
}

void FileReader::ReadFile(){
    std::string token;
    std::ifstream file(FilePath);
    std::string str;
    int lineCount = LineCount();
    TreeList* data = new TreeList(lineCount);
    BSTNode* tempRoot = nullptr;
    BST* tempTree = new BST();
    BST* treeToSave = nullptr;
    Stack* tempStack = nullptr;
    int stackPeekVal = 0;
    int treeIndex = 0;
    int value = 0;

    while (std::getline(file, token)) 
    {
        // each loop is a line
        std::istringstream ss(token);
        while (std::getline(ss, str, ' ')) 
        {
            value = stoi(str);
            if(tempStack == nullptr || tempStack->Size() == 0){
                tempStack = new Stack(value);
                continue;
            }

            // if the new value is even and greater than what is on top of the stack, we create a tree, and compare it to our saved tree
            stackPeekVal = tempStack->Peek();
            if(value % 2 == 0 && value > stackPeekVal){

                // We create a temp tree and compare
                while (tempStack->Size() > 0)
                {
                    tempRoot = tempTree->InsertNode(tempRoot,tempStack->Pop());
                }
                
                tempTree->root = tempRoot;
                treeToSave = GetTreeToBeSaved(treeToSave,tempTree);

                data->SetTreeAtIndex(treeIndex,treeToSave);
                
                tempTree = new BST();
                tempRoot = nullptr;
            }

            tempStack->Push(value);
        }

        if(tempStack->Size()>0){
            BST* newTempTree = new BST();

            while (tempStack->Size() > 0)
            {
                tempRoot = newTempTree->InsertNode(tempRoot,tempStack->Pop());
            }

            newTempTree->root = tempRoot;
            treeToSave = GetTreeToBeSaved(treeToSave,newTempTree);
            
            data->SetTreeAtIndex(treeIndex,treeToSave);
        }

        treeIndex++;
        tempTree = new BST();
        treeToSave = nullptr;
        tempRoot = nullptr;
    }

    Data = data;
    file.close();
}

TreeList* FileReader::GetTreeList(){
    ReadFile();
    return this->Data;
}

BST* FileReader::GetTreeToBeSaved(BST* firstTree, BST* secondTree){

    if(firstTree == nullptr){
        if(secondTree == nullptr){
            return nullptr;
        }
        
        return secondTree;
    }

    if(secondTree == nullptr){
        return firstTree;
    }
    
    if(firstTree->GetHeight() > secondTree->GetHeight()){
        return firstTree;
    } else if(firstTree->GetHeight() < secondTree->GetHeight()){
        return secondTree;
    }else{
        if(firstTree->GetSumOfNodeValues() > secondTree->GetSumOfNodeValues())
            return firstTree;
        else
            return secondTree;
    }
}

int FileReader::LineCount() 
{
    int counter = 0;
    std::ifstream file(this->FilePath);
    std::string unused;
    while (std::getline(file, unused))
        ++counter;

    file.close();
    return counter;
}

FileReader::~FileReader(){
    delete Data;
}