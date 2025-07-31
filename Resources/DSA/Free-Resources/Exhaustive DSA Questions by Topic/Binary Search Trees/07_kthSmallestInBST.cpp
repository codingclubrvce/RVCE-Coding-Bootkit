#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int ans = 0;

void f(Node* root, int& k){
    if(!root) return;
    f(root->left, k);
    k--;
    if(k == 0){
        ans = root->data;
        return;
    }
    f(root->right, k);
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->right = new Node(14);
    
    int k;
    cout << "Enter value of k: ";
    cin >> k;
    f(root, k);
    cout << ans << endl;

    return 0;
}