#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* back;
    // constructors
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
};

Node* convertToDLL(vector<int> &nums){
    Node* head = new Node(nums[0]);
    Node* prev = head;
    for(int i = 1; i<nums.size(); i++){
        Node* temp = new Node(nums[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
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

Node* insertBeforeHead(Node* head, int val){
    Node* newNode = new Node(val, head, nullptr);
    head->back = newNode;
    return newNode;
}

Node* insertBeforeTail(Node*head, int val){
    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
    Node* head = convertToDLL(nums);
    display(head);
    head = insertBeforeHead(head, 0);
    display(head);
    head = insertBeforeTail(head, 10);
    display(head);
    return 0;
}