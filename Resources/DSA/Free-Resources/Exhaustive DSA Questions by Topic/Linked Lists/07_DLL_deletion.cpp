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

Node* deleteHead(Node* head){
    // edge case: DLL containing either no element or one element
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }
    // for DLL containing more than one element
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* prev = temp->back;
    temp->back = nullptr;
    prev->next = nullptr;
    delete temp;
    return head;
}

Node* deleteK(Node* head, int k){
    if(head == nullptr){
        return nullptr;
    }
    int count = 0;
    Node* temp = head;
    while(temp != nullptr){
        count++;
        if(count == k){
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    if(prev == nullptr && front == nullptr){
        return nullptr;
    }
    else if(prev == nullptr){
        return deleteHead(head);
    }
    else if(front == nullptr){
        return deleteTail(head);
    }
    else{
        prev->next = front;
        front->back = prev;
        temp->next = nullptr;
        temp->back = nullptr;
        delete temp;
    }
    return head;
}

void deleteNode(Node* temp){
    // given that temp is never equal to head
    Node* prev = temp->back;
    Node* front = temp->next;
    if(front == nullptr){
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* head = convertToDLL(nums);
    display(head);
    head = deleteHead(head);    
    display(head);
    head = deleteTail(head);
    display(head);
    head = deleteK(head, 2);
    display(head);
    deleteNode(head->next->next);
    display(head);
    return 0;
}