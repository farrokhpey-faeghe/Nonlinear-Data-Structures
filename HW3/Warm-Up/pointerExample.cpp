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
        key = __________;
    }
};

int main()
{
    // Create the root node
    Node* root = new Node(____);

    // Create two more nodes
    Node* node4 = new Node(____);
    Node* node11 = new Node(____);


    // Connect the left and right children to root
    root->left = __________;
    root->right = __________;


    // Set the parent pointers
    node4->parent = __________;
    node11->parent = __________;


    // Print the root
    cout << "Root: "
         << __________
         << endl;


    // Print the left child
    cout << "Left child: "
         << __________
         << endl;


    // Print the right child
    cout << "Right child: "
         << __________
         << endl;


    // Print the parent of node 4
    cout << "Parent of 4: "
         << __________
         << endl;


    // Move through the tree using a pointer
    Node* current = root;

    current = current->__________;

    cout << "Current node: "
         << current->__________
         << endl;


    return 0;
}
