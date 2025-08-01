#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* lca(Node* root, int x, int y){
    if(root==nullptr || root->data == x || root->data == y){
        return root;
    }
    Node* l = lca(root->left, x, y);
    Node* r = lca(root->right, x, y);
    if(l==nullptr) return r;
    else if(r==nullptr) return l;
    else return root;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    root->right->left = new Node(8);
    root->right->right = new Node(9);
    Node* ans = lca(root, 8, 7);
    cout << "Lowest Common Ancestor: " << ans->data << endl;
    return 0;
}