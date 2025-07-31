#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    Node *left;
    Node *right;
} NODE;

class Queue
{
    NODE **Q;
    int front;
    int rear;
    int size;

public:
    Queue(int size){
        this->size = size;
        front = rear = -1;
        Q = new NODE *[size];
    }
    bool isEmpty(){
        return front == rear;
    }
    bool isFull(){
        return rear == size - 1;
    }
    void enqueue(NODE *x){
        if (isFull()){
            cout << "Queue is full" << endl;
        }
        else{
            rear++;
            Q[rear] = x;
        }
    }
    NODE *dequeue(){
        if (isEmpty()){
            cout << "Queue is empty" << endl;
            return nullptr;
        }
        else{
            return Q[++front];
        }
    }
};

class Tree{
    NODE *root;
    
public:
    Tree(){
        root = nullptr;
    }
    void createTree();
    void Preorder(){Preorder(root);}
    void Preorder(Node* p);
    void Inorder() { Inorder(root); }
    void Inorder(Node* p);
    void Postorder() { Postorder(root); }
    void Postorder(Node* p);
    void Levelorder() { Levelorder(root); }
    void Levelorder(Node* p);
    int Height() { return Height(root); }
    int Height(Node* root);
};

void Tree::createTree(){
    NODE *p, *t;
    int x;
    Queue q(100);
    cout << "Enter root value: ";
    cin >> x;
    root = new NODE;
    root->data = x;
    root->left = root->right = nullptr;
    q.enqueue(root);
    while(!q.isEmpty()){
        p = q.dequeue();
        cout << "Enter left child of " << p->data << "(-1 to stop) : ";
        cin >> x;
        if(x!=-1){
            t = new NODE;
            t->data = x;
            t->left = t->right = nullptr;
            p->left = t;
            q.enqueue(t);
        }
        cout << "Enter right child of " << p->data << "(-1 to stop) : ";
        cin >> x;
        if(x!=-1){
            t = new NODE;
            t->data = x;
            t->left = t->right = nullptr;
            p->right = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(NODE* p){
    if(p){
        cout << p->data << " ";
        Preorder(p->left);
        Preorder(p->right);
    }
}

void Tree::Inorder(NODE* p){
    if(p){
        Inorder(p->left);
        cout << p->data << " ";
        Inorder(p->right);
    }
}   

void Tree::Postorder(NODE* p){
    if(p){
        Postorder(p->left);
        Postorder(p->right);
        cout << p->data << " ";
    }
}   

void Tree::Levelorder(NODE* root){
    Queue q(100);
    if(root){
        cout << root->data << " ";
        q.enqueue(root);
    }
    while(!q.isEmpty()){
        root = q.dequeue();
        if(root->left){
            cout << root->left->data << " ";
            q.enqueue(root->left);
        }
        if(root->right){
            cout << root->right->data << " ";
            q.enqueue(root->right);
        }
    }
}

int Tree::Height(NODE* root){
    if(!root){
        return 0;
    }
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int main(){
    Tree t;
    t.createTree();
    cout << "Preorder Traversal: ";
    t.Preorder();
    cout << endl;
    cout << "Inorder Traversal: ";
    t.Inorder();
    cout << endl;
    cout << "Postorder Traversal: ";
    t.Postorder();
    cout << endl;
    cout << "Level Order Traversal: ";
    t.Levelorder();
    cout << endl;
    cout << "Height of the Tree: " << t.Height() << endl;
    return 0;
}