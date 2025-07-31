#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isLeaf(Node* root){
    return !root->right && !root->left;
}

vector<int> leftTrav;
vector<int> bottomTrav;
vector<int> rightTrav;

void leftBoundary(Node* root){
    if(!root || isLeaf(root)) return;
    leftTrav.push_back(root->data);
    cout << "Pushed to left " << root->data << endl;
    if(root->left) leftBoundary(root->left);
    else leftBoundary(root->right); // Only go right if left is null
}

void bottom(Node* root){
    if(!root) return;
    if(isLeaf(root)) {
        bottomTrav.push_back(root->data);
        cout << "Pushed to bottom " << root->data << endl;
        return;
    }
    bottom(root->left);
    bottom(root->right);
}

void rightBoundary(Node* root){
    if(!root || isLeaf(root)){
        return;
    }
    if(root->right) rightBoundary(root->right);
    else rightBoundary(root->left); // Only go left if right is null
    rightTrav.push_back(root->data);
    cout << "Added to right " << root->data << endl;
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
    root->left->left->right = new Node(8);
    root->right->right->right = new Node(9);
    
    leftTrav.push_back(root->data);
    leftBoundary(root->left);
    bottom(root);
    rightBoundary(root->right);
    
    for(int i = 0; i < leftTrav.size(); i++){
        cout << leftTrav[i] << " ";
    }
    for(int i = 0; i < bottomTrav.size(); i++){
        cout << bottomTrav[i] << " ";
    }
    for(int i = 0; i < rightTrav.size(  ); i++){ 
        cout << rightTrav[i] << " ";
    }

    return 0;
}