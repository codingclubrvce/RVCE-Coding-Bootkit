#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int check(Node* p, Node* q){
    if(!p || !q){
        return p==q;
    }
    return (p->data == q->data) && check(p->left, q->left) && check(p->right, q->right);
}

int main()
{
    Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    Node* root1 = new Node(-10);
    root1->left = new Node(9);
    root1->right = new Node(20);
    root1->right->left = new Node(15);
    root1->right->right = new Node(7);

    if(check(root, root1)) cout << "Identical" << endl;
    else cout << "Different" << endl;
    return 0;
}
