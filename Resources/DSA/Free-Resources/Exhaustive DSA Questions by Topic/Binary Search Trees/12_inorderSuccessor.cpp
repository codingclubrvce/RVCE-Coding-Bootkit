#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int main()
{
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->right = new Node(14);
    
    int val = 8;
    int ans = 0;

    while(root){
        if(val >= root->data){
            root = root->right;
        }
        else{
            ans = root->data;
            root = root->left;
        }
    }

    cout << ans << endl;

    return 0;
}