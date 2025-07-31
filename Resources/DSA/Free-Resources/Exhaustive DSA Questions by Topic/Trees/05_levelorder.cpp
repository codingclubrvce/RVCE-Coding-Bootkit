#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> levelorder(Node* root){
    vector<int> result;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* t = q.front();
        q.pop();
        result.push_back(t->data);
        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);
    }
    return result;
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
    vector<int> result = levelorder(root);
    cout << "Level order Traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
