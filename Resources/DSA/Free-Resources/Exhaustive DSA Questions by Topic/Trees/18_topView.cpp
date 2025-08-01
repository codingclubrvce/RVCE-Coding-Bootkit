#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> traverse(Node* root){
    queue<pair<Node*, pair<int, int>>> q;
    map<int, int> nodes;
    q.push({root, {0, 0}});
    while(!q.empty()){
        auto p = q.front();
        Node* temp = p.first; // node
        int x = p.second.first; // vertical
        int y = p.second.second; // level
        if(!nodes[x]) nodes[x] = temp->data;
        q.pop();
        if(temp->left) q.push({temp->left, {x-1, y+1}});
        if(temp->right) q.push({temp->right, {x+1, y+1}});
    }
    vector<int> ans;
    for(auto it:nodes){
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);
    
    vector<int> ans = traverse(root);

    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}