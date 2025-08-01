#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool getPath(vector<int> &result, Node* root, int x){
    if(!root) return false;
    result.push_back(root->data);
    if(root->data == x) return true;
    if(getPath(result, root->left, x) || getPath(result, root->right, x)) return true;
    result.pop_back();
    return false;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    vector<int> result;
    bool flag = getPath(result, root, 7);
    if(flag){
        for(int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }
    else cout << "Path does not exist!" << endl;
    return 0;
}