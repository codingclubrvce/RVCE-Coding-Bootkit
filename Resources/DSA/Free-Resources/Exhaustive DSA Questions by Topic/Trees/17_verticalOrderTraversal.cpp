#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> traverse(Node* root){
    queue<pair<Node*, pair<int, int>>> q;
    map<int, map<int, multiset<int>>> nodes;
    q.push({root, {0, 0}});
    while(!q.empty()){
        auto p = q.front();
        Node* temp = p.first; // node
        int x = p.second.first; // vertical
        int y = p.second.second; // level
        nodes[x][y].insert(temp->data);
        q.pop();
        if(temp->left) q.push({temp->left, {x-1, y+1}});
        if(temp->right) q.push({temp->right, {x+1, y+1}});
    }
    vector<vector<int>> ans;
    for(auto it:nodes){
        vector<int> col;
        for(auto p : it.second){
            col.insert(col.end(), p.second.begin(), p.second.end());
        }
        ans.push_back(col);
    }
    return ans;
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
    root->left->left->right = new Node(8);
    root->right->right->right = new Node(9);
    
    vector<vector<int>> ans = traverse(root);

    for(int i = 0; i<ans.size(); i++){
        cout << "[ ";
        for(int j = 0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}