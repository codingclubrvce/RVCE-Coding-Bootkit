#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int w;

void width(Node* root){
    if(!root){
        w = 0;
        return;
    }
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        int l = q.size();
        int x = 0;
        int y = 0;
        int m = q.front().second;
        for(int k = 0; k<l; k++){
            auto p = q.front();
            Node* n = p.first;
            int i = p.second-m;
            if(k == 0){
                x = i;
            }
            y = i;
            q.pop();
            if(n->left) q.push({n->left, 2*i+1});
            if(n->right) q.push({n->right, 2*i+2});
        }
        w = max(w, y-x)+1;
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    root->right->right = new Node(9);
    width(root);
    cout << "Width: " << w << endl;
    return 0;
}