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

Node* brute(Node* head){
    Node* temp = head;
    vector<int> arr;
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    while(temp != nullptr && temp->next != nullptr){
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp){
        arr.push_back(temp->data);
    }
    temp = head->next;
    while(temp != nullptr && temp->next != nullptr){
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp){
        arr.push_back(temp->data);
    }
    temp = head;
    for(int i = 0; i<arr.size(); i++){
        temp->data = arr[i];
        temp = temp->next;
    }
    return head;
}

Node* optimal(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;
    while(even != nullptr && even->next != nullptr){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    Node* head = convertToLL(nums);
    display(head);
    // head = brute(head);
    head = optimal(head);
    display(head);
    return 0;
}