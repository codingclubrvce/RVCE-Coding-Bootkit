#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    // Constructor
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void display(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

Node* insertEnd(Node* head, int val){
    Node* newNode = new Node(val, nullptr);
    if(head == nullptr){
        return newNode;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* insertK(Node* head, int k, int val){
    if(head==nullptr){
        if(k==1){
            return new Node(val);
        }
        else{
            return nullptr;
        }
    }
    if(k==1){
        return new Node(val, head);
    }
    int count = 0;
    Node* temp = head;
    while(temp != nullptr){
        count++;
        if(count == k-1){
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

Node* insertBeforeX(Node* head, int val, int x){
    if(head==nullptr){
        return nullptr;
    }
    if(x==head->data){
        return new Node(val, head);
    }
    Node* temp = head;
    while(temp->next != nullptr){
        if(temp->next->data == x){
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {2, 5, 8, 7, 10, 13, 16, 19};
    Node* head = convertToLL(arr);
    display(head);
    head = insertHead(head, 1);
    display(head);
    head = insertEnd(head, 88);
    display(head);
    head = insertK(head, 4, 6);
    display(head);
    head = insertBeforeX(head, 1000, 10);
    display(head);
    return 0;
}
