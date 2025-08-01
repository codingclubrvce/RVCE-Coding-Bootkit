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

Node* deleteHead(Node* head){
    if(head==NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node* deleteLast(Node* head){
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    temp->next = nullptr;
    return head;
}

Node* deleteK(Node* head, int k){
    if(head == nullptr){
        return head;
    }
    if(k==1){
        return deleteHead(head);
    }
    int count = 0;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp){
        count++;
        if(count == k){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp; // if k has not been found, then make temp the previous node and move temp one ahead.
        temp = temp->next;
    }
    return head;
}

Node* deleteValue(Node* head, int val){
    if(head == nullptr){
        return head;
    }
    if(head->data == val){
        return deleteHead(head);
    }
    Node* temp = head;
    Node* prev;
    while(temp){
        if(temp->data == val){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {2, 5, 8, 7, 10, 13, 16, 19};
    Node* head = convertToLL(arr);
    display(head);
    head = deleteHead(head);
    display(head);
    head = deleteLast(head);
    display(head);
    head = deleteK(head, 1);
    display(head);
    head = deleteValue(head, 8);
    display(head);
    return 0;
}
