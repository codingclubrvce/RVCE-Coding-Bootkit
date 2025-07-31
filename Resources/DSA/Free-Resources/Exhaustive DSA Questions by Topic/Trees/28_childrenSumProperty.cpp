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

void change(Node* root){
    if(!root) return;
    int child = 0;
    if(root->left) child = child+root->left->data;
    if(root->right) child = child+root->right->data;
    if(root->data >= child){
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }
    else{
        root->data = child;
    }
    change(root->left);
    change(root->right);
    int total = 0;
    if(root->left) total = total + root->left->data;
    if(root->right) total = total + root->right->data;
    if(root->left || root->right) root->data = total;
}

void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
int main()
{
    Node* root = new Node(40);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right->left = new Node(30);
    root->right->right = new Node(40);
    inorderTraversal(root);
    cout << endl;
    change(root);
    inorderTraversal(root);
    return 0;
}