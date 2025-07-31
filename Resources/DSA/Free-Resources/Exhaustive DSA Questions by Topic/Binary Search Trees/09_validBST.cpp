#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int pr = INT_MIN;

bool f(Node* root){
    if(!root) return true;
    if(!f(root->left)) return false;
    if(root->data <= pr && pr != INT_MIN) return false;
    pr = root->data;
    return f(root->right);
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->right = new Node(14);
    
    if(f(root)) cout << "Valid BST" << endl;
    else cout << "Invalid BST" << endl;

    return 0;
}