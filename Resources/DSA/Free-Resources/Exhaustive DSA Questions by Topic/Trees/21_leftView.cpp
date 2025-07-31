#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> ans;

void traverse(Node* root, int level){
    if(!root) return;
    if(ans.size()==level){
        ans.push_back(root->data);
    }
    traverse(root->left, level+1);
    traverse(root->right, level+1);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->left->right->left = new Node(6);
    
    traverse(root, 0);

    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}