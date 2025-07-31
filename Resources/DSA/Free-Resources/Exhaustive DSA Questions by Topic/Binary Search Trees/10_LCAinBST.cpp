#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* f(Node* root, Node* p, Node* q){
    if(!root || root==p || root==q) return root;
    if(p->data < root->data && q->data > root->data) return root;
    if(p->data > root->data && q->data < root->data) return root;
    if(p->data < root->data && q->data < root->data) return f(root->left, p, q);
    return f(root->right, p, q);
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->right = new Node(14);
    
    Node* p = root->left->left;
    Node* q = root->left->right;

    Node* lca = f(root, p, q);
    cout << lca->data << endl;

    return 0;
}