#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int ans = 0;

void insert(Node* root, int x){
    if(!root) return;
    if(root->data < x){
        if(!root->right){
            root->right = new Node(x);
        }
        else{
            insert(root->right, x);
        }
    }
    else if(root->data > x){
        if(!root->left){
            root->left = new Node(x);
        }
        else{
            insert(root->left, x);
        }
    }
}

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
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->right = new Node(14);
    
    int x;
    cout << "Enter value to insert: ";
    cin >> x;

    cout << "Before insertion: ";
    vector<int> arr = levelorder(root);
    for(int i = 0; i<arr.size(); i++) cout << arr[i] << " ";
    cout << endl;

    insert(root, x);

    cout << "After insertion: ";
    arr = levelorder(root);
    for(int i = 0; i<arr.size(); i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}