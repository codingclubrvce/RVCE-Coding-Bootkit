#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int lefth(Node* root){
    int h = 0;
    while(root){
        h++;
        root = root->left;
    }
    return h;
}

int righth(Node* root){
    int h = 0;
    while(root){
        h++;
        root = root->right;
    }
    return h;
}

int count(Node* root){
    if(!root) return 0;
    int lh = lefth(root);
    int rh = righth(root);
    if(lh==rh) return (1<<lh)-1;
    return 1 + count(root->left) + count(root->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    int c = count(root);
    cout << c << endl;
    return 0;
}