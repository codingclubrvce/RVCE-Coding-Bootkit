#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorder(Node* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* generate(vector<int> pre, int ps, int pe, vector<int> in, int is, int ie, map<int, int> inMap){
    if(ps>pe || is>ie) return nullptr;
    Node* root = new Node(pre[ps]);
    int inRoot = inMap[root->data];
    int numsleft = inRoot - is;
    root->left = generate(pre, ps+1, ps+numsleft, in, is, inRoot-1, inMap);
    root->right = generate(pre, ps+1+numsleft, pe, in, inRoot+1, ie, inMap);
    return root;
}

int main()
{
    vector<int> in = {40, 20, 50, 10, 60, 30};
    vector<int> pre = {10, 20, 40, 50, 30, 60};
    map<int, int> inMap;
    for(int i = 0; i<in.size(); i++){
        inMap[in[i]] = i;
    }
    Node* root = generate(pre, 0, pre.size()-1, in, 0, in.size()-1, inMap);
    inorder(root);
}