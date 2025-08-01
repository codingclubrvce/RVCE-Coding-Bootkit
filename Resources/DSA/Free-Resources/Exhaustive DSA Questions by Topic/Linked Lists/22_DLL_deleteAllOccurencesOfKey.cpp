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

Node* deleteKey(Node* head, int key){
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == key){
            if(temp == head){
                head = head->next;
            }
            Node* front = temp->next;
            Node* prev = temp->back;
            if(front) front->back = prev;
            if(prev) prev->next = front;
            delete(temp);
            temp = front;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}

int main(){
    vector<int> nums = {10, 4, 10, 10, 6, 10};
    Node* head = convertToDLL(nums);
    display(head);
    head = deleteKey(head, 10);
    display(head);
}