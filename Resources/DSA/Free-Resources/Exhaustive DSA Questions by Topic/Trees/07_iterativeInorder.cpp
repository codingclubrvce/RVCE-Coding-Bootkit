#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorder(Node* root){
    stack<Node*> st;
    Node* t = root;
    while(true){
        if(t){
            st.push(t);
            t = t->left;
        }
        else{
            if(st.empty()) break;
            t = st.top();
            st.pop();
            cout << t->data << " ";
            t = t->right;
        }
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    inorder(root);
    return 0;
}
