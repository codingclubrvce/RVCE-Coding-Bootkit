#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool search(Node* root, int x){
    if(!root) return false;
    if(root->data == x){
        return true;
    }
    else if(root->data < x){
        return search(root->right, x);
    }
    else if(root->data > x){
        return search(root->left, x);
    }
    return false;
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->right = new Node(14);
    
    int x;
    cout << "Enter value to search: ";
    cin >> x;

    if(search(root, x)){
        cout << "Found" << endl;
    }
    else cout << "Not Found" << endl;
    return 0;
}