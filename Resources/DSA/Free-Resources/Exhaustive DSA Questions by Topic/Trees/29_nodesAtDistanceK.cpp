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
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    Node* target = root->left;
    int k = 2;
    unordered_map<Node*, Node*> parent;
    queue<Node*> q;
    q.push(root);
    parent[root] = nullptr;
    while(!q.empty()){
        Node* p = q.front();
        q.pop();
        if(p->left){
            parent[p->left] = p;
            q.push(p->left);
        }
        if(p->right){
            parent[p->right] = p;
            q.push(p->right);
        }
    }
    unordered_map<Node*, int> vis;
    vis[target] = 1;
    q.push(target);
    int dis = 0;
    while(!q.empty() && dis<k){
        dis++;
        int len = q.size();
        for(int i = 0; i<len; i++){
            Node* current = q.front();
            q.pop();
            Node *up=nullptr, *l=nullptr, *r=nullptr;
            if(parent[current]){
                up = parent[current];
            }
            if(current->left){
                l = current->left;
            }
            if(current->right){
                r = current->right;
            }
            if(up && !vis[up]){
                q.push(up);
                vis[up] = 1;
            }
            if(l && !vis[l]){
                q.push(l);
                vis[l] = 1;
            }
            if(r && !vis[r]){
                q.push(r);
                vis[r] = 1;
            }
        }
    }
    while(!q.empty()){
        cout << q.front()->data << " ";
        q.pop();
    }
    return 0;
}