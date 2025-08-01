#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int i = 0;

Node* f(vector<int>& pre, int ub){
    if(i==pre.size() || pre[i] > ub){
        return nullptr;
    }
    Node* root = new Node(pre[i++]);
    root->left = f(pre, root->data);
    root->right = f(pre, ub);
    return root;
}

void display(Node* root){
    if(!root) return;
    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

int main()
{
    vector<int> pre = {8, 5, 1, 7, 10, 12};
    
    Node* root = f(pre, INT_MAX);
    display(root);

    return 0;
}