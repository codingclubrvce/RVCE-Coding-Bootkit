#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    // constructors
    Node(int data1){
        data = data1;
        next = nullptr;
    }
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
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
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

Node* rotate(Node* head, int k){
    if(head == nullptr || k == 0 || head->next == nullptr){
        return head;
    }
    Node* tail = head;
    int len = 1;
    while(tail->next != nullptr){
        len++;
        tail = tail->next;
    }
    if(k%len == 0) {
        return head;
    }
    k = k%len;
    tail->next = head;
    Node* temp = head;
    int reach = len - k - 1;
    while(reach--){
        temp = temp->next;
    }
    head = temp->next;
    temp->next = nullptr;
    return head;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    Node* head = convertToLL(nums);
    display(head);
    head = rotate(head, 2);
    display(head);
    return 0;
}