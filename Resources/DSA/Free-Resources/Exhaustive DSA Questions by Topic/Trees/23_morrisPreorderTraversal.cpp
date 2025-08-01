#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> preOrder(Node* root){
    vector<int> pre;
    Node* cur = root;
    while(cur != nullptr){
        if(cur->left == nullptr){
            pre.push_back(cur->data);
            cur = cur->right;
        }
        else{
            Node* prev = cur->left;
            while(prev->right && prev->right != cur){
                prev = prev->right;
            }
            if(prev->right == nullptr){
                prev->right = cur;
                pre.push_back(cur->data);
                cur = cur->left;
            }
            else{
                prev->right = nullptr;
                cur = cur->right;
            }
        }
    }
    return pre;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    vector<int> result = preOrder(root);
    cout << "Preorder Traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}