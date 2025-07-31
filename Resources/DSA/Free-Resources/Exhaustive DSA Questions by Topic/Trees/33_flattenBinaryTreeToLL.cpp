#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void find(Node* root, Node*& last){
    if(!root) return;
    last = root;
    find(root->left, last);
    find(root->right, last);
}

void flatten(Node* root){
    if(!root) return;
    if(root->left){
        Node* last = nullptr;
        find(root->left, last);
        last->right = root->right;
        root->right = root->left;
        root->left = nullptr;
    }
    flatten(root->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(7);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    flatten(root);
    while(root){
        cout<<root->data<<" ";
        root = root->right;
    }
    return 0;
}