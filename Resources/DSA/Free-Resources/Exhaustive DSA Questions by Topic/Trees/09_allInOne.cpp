#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void traverse(Node* root){
    stack<pair<Node*, int>> st;
    vector<int> pre;
    vector<int> in;
    vector<int> post;
    st.push({root, 1});
    while(!st.empty()){
        if(st.top().second == 1){
            pre.push_back(st.top().first->data);
            st.top().second++;
            if(st.top().first->left) st.push({st.top().first->left, 1});
        }
        else if(st.top().second == 2){
            in.push_back(st.top().first->data);
            st.top().second++;
            if(st.top().first->right) st.push({st.top().first->right, 1});
        }
        else{
            post.push_back(st.top().first->data);
            st.pop();
        }
    }
    cout << "Pre order: ";
    for(int i : pre) cout << i << " ";
    cout << endl;
    cout << "In order: ";
    for(int i : in) cout << i << " ";
    cout << endl;
    cout << "Post order: ";
    for(int i : post) cout << i << " ";
    cout << endl;
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
    traverse(root);
    return 0;
}
