#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool symmetric(Node* p, Node* q){
    if(p==nullptr || q==nullptr){
        return p==q;
    }
    return (p->data == q->data) && symmetric(p->left, q->right) && symmetric(p->right, q->left);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);
    if(!root) cout << "Symmetric Trees" << endl;
    if(symmetric(root->left, root->right)) cout << "Symmetric Trees"<< endl;
    else cout << "Not symmetric" << endl;

    return 0;
}