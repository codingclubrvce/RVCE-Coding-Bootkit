#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int ans = -1;

int maxPathSum(Node* root){
    if(root == nullptr) return 0;
    int leftPathSum = maxPathSum(root->left);
    leftPathSum = max(leftPathSum, 0);
    int rightPathSum = maxPathSum(root->right);
    rightPathSum = max(rightPathSum, 0);
    ans = max(ans, root->data + leftPathSum + rightPathSum);
    return root->data + max(leftPathSum, rightPathSum);
}

int main()
{
    Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    int h = maxPathSum(root);
    cout << "Max Path Sum: " << ans << endl;
    return 0;
}
