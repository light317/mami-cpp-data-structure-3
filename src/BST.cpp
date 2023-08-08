// Binary Search Tree

#include <iostream>
#include "BST.hpp"

BST::BST(){
    this->root = nullptr;
}

BST::BST(BSTNode* start){
    this->root = start;
    this->root->left = nullptr;
    this->root->right = nullptr;
}

void BST::PrintInOrder(BSTNode* root) {
  if (root != nullptr) {
    // Traverse left
    PrintInOrder(root->left);

    // Traverse root
    std::cout << root->key << " -> ";

    // Traverse right
    PrintInOrder(root->right);
  }
}

void BST::PrintPostOrder(){
  return PrintPostOrder(root);
}

void BST::PrintPostOrder(BSTNode* root) {
  if (root != nullptr) {
    // Traverse left
    PrintPostOrder(root->left);

    // Traverse right
    PrintPostOrder(root->right);

    // Traverse root
    std::cout <<(char)root->key << " ";
  }
}

BSTNode* BST::InsertNode(BSTNode* node, int key) {
  // Return a new node if the tree is empty
  if (node == nullptr) {
    root = new BSTNode(key);
    return root;
  }

if(node->key == key){
  // To avoid duplicate entries
  return node;
}
  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = InsertNode(node->left, key);
  else
    node->right = InsertNode(node->right, key);

  return node;
}

BSTNode* BST::MinValueNode(BSTNode* node) {
  BSTNode* current = node;

  // Find the leftmost leaf
  while (current && current->left != nullptr)
    current = current->left;

  return current;
}

BSTNode* BST::DeleteNode(BSTNode *root, int key) {
  // Return if the tree is empty
  if (root == nullptr) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = DeleteNode(root->left, key);
  else if (key > root->key)
    root->right = DeleteNode(root->right, key);
  else {
    // If the node is with only one child or no child
    if (root->left == nullptr) {
      BSTNode* temp = root->right;
      delete root;
      //free(root);
      return temp;
    } else if (root->right == nullptr) {
      BSTNode* temp = root->left;
      //free(root);
      delete root;
      return temp;
    }

    // If the node has two children
    BSTNode* temp = MinValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = DeleteNode(root->right, temp->key);
  }
  return root;
}

int BST::GetHeight(BSTNode* node)
{
    // base case tree is empty
    if (node == nullptr)
        return 0;
 
    // If tree is not empty then
    // height = 1 + max of left height
    // and right heights
    return 1 + max(GetHeight(node->left), GetHeight(node->right));
}

int BST::GetHeight()
{
  return GetHeight(root);
}

int BST::max(int a, int b) {
  return (a > b) ? a : b;
}

bool BST::IsBalanced(BSTNode* treeRoot)
{

    int leftTreeHeight = 0;
    int rightTreeHeight = 0;
 
    if (treeRoot == nullptr){
        return true;
    }
 
    leftTreeHeight = GetHeight(treeRoot->left);
    rightTreeHeight = GetHeight(treeRoot->right);
 
    if (abs(leftTreeHeight - rightTreeHeight) <= 1 && IsBalanced(treeRoot->left)
        && IsBalanced(treeRoot->right)){
        return true;
        }
 
    return false;
}

int BST::GetSumOfNodeValues(){
  return GetSumOfNodeValues(root);
}

int BST::GetSumOfNodeValues(BSTNode* root){
  if(root == nullptr)
    return 0;

  if(root->left == nullptr && root->right == nullptr)
    return root->key;

  return root->key + GetSumOfNodeValues(root->right) + GetSumOfNodeValues(root->left);
}

BSTNode* BST::Clone(BSTNode* rootToClone)
{
    // base case
    if (rootToClone == nullptr) {
        return nullptr;
    }
 
    // create a new node with the same data as the root node
    BSTNode* root_copy = new BSTNode(rootToClone->key);
 
    // clone the left and right subtree
    root_copy->left = Clone(rootToClone->left);
    root_copy->right = Clone(rootToClone->right);
 
    // return cloned root node
    return root_copy;
}

BSTNode* BST::Clone(){
  return Clone(root);
}
