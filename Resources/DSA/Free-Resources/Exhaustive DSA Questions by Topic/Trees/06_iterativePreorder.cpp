#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void preorder(Node* root){
    stack<Node*> st;
    st.push(root);
    while(st.top()){
        Node* t = st.top();
        st.pop();
        cout << t->data << " ";
        if(t->right) st.push(t->right);
        if(t->left) st.push(t->left);
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
    preorder(root);
    return 0;
}
