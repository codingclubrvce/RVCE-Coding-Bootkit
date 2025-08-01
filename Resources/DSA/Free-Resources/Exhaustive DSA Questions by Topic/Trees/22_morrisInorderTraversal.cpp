#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> inOrder(Node* root){
    vector<int> in;
    Node* cur = root;
    while(cur != nullptr){
        if(cur->left == nullptr){
            in.push_back(cur->data);
            cur = cur->right;
        }
        else{
            Node* prev = cur->left;
            while(prev->right && prev->right != cur){
                prev = prev->right;
            }
            if(prev->right == nullptr){
                prev->right = cur;
                cur = cur->left;
            }
            else{
                prev->right = nullptr;
                in.push_back(cur->data);
                cur = cur->right;
            }
        }
    }
    return in;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    vector<int> result = inOrder(root);
    cout << "Inorder Traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}