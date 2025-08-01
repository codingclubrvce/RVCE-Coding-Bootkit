#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int largest(Node* root){
    Node* temp = root;
    while(root && root->right){
        root = root->right;
    }
    return root->data;
}

int smallest(Node* root){
    Node* temp = root;
    while(root && root->left){
        root = root->left;
    }
    return root->data;
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->left->left = new Node(1);
    root->left->right = new Node(9);
    root->right->right = new Node(14);
    
    cout << "Smallest: " << smallest(root) << endl;
    cout << "Largest: " << largest(root) << endl;

    return 0;
}