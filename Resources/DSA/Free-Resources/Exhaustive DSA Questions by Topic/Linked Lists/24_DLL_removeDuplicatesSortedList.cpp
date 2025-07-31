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

Node* deleteDuplicates(Node* head){
    Node* temp = head;
    while(temp != nullptr && temp->next != nullptr){
        Node* front = temp->next;
        while(front != nullptr && front->data == temp->data){
            front = front->next;
        }
        temp->next = front;
        if(front != nullptr) front->back == temp;
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> nums = {1, 1, 1, 2, 3, 3, 4};
    Node* head = convertToDLL(nums);
    display(head);
    head = deleteDuplicates(head);
    display(head);
}