#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


int ans = 0;

int depth(Node* root){
    if(root == nullptr) return 0;
    int lh = depth(root->left);
    int rh = depth(root->right);
    ans = max(ans, lh+rh);
    return 1 + max(lh, rh);
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
    root->right->right->right = new Node(8);
    root->right->right->right->right = new Node(8);
    int h = depth(root);
    cout << "Diameter: " << ans << endl;
    return 0;
}
