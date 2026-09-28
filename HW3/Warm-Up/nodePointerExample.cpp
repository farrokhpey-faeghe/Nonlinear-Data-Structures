#include <iostream>
using namespace std;

class Node
{
public:
    int key;

    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;

    Node(int nodeKey)
    {
        key = nodeKey;
    }
};

int main()
{
    Node* root = new Node(9);

    // Create the tree
    root->left = new Node(____);
    root->right = new Node(____);

    root->left->left = new Node(____);
    root->left->right = new Node(____);


    // Set parent pointers
    root->left->parent = __________;
    root->right->parent = __________;

    root->left->left->parent = __________;
    root->left->right->parent = __________;


    // Start at the root
    Node* current = __________;


    // Move from 9 to 4
    current = current->__________;


    // Move from 4 to 6
    current = current->__________;


    cout << "Current node: "
         << current->__________
         << endl;


    // Check whether node 6 has a left child
    if (current->__________ == nullptr)
    {
        cout << "No left child" << endl;
    }


    return 0;
}
