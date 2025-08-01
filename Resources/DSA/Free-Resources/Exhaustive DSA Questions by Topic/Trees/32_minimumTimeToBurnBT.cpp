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
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(7);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    Node* target = root->left;
    unordered_map<Node*, Node*> parent;
    queue<Node*> q;
    q.push(root);
    parent[root] = nullptr;
    // Level order traversal to mark parents
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
    int ans = 0;
    while(!q.empty()){
        int x = 0;
        int len = q.size();
        for(int i = 0; i<len; i++){
            Node* current = q.front();
            q.pop();
            if(parent[current] && !vis[parent[current]]){
                x = 1;
                q.push(parent[current]);
                vis[parent[current]] = 1;
            }
            if(current->left && !vis[current->left]){
                x = 1;
                q.push(current->left);
                vis[current->left] = 1;
            }
            if(current->right && !vis[current->right]){
                x = 1;
                q.push(current->right);
                vis[current->right] = 1;
            }
        }
        if(x) ans++;
    }
    cout << ans << endl;
    return 0;
}