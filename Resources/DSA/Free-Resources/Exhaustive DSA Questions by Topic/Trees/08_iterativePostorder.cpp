#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void postorder(Node* root){
    stack<Node*> s1;
    if(root) s1.push(root);
    stack<Node*> s2;
    Node* t = root;
    while(!s1.empty()){
        t = s1.top();
        s2.push(t);
        s1.pop();
        if(t->left) s1.push(t->left);
        if(t->right) s1.push(t->right);
    }
    while(!s2.empty()){
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

void postorder2(Node* root){
    stack<Node*> st;
    Node* curr = root;
    Node* temp = nullptr;
    while(curr || !st.empty()){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }
        else{
            temp = st.top()->right;
            if(temp == nullptr){
                temp = st.top();
                st.pop();
                cout << temp->data << " ";
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }
            else{
                curr = temp;
            }
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
    postorder2(root);
    return 0;
}
