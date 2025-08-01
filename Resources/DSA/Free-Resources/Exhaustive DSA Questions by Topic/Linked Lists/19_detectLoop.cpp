#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;        
    Node* next;      
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

bool brute(Node* head){
    unordered_map<Node*, int> mpp;
    Node* temp = head;
    while(temp != nullptr){
        if(mpp[temp] == 1){
            return true;
        }
        mpp[temp]++;
        temp = temp->next;
    }
    return false;
}

bool optimal(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third; 
    if (optimal(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;
    return 0;
}