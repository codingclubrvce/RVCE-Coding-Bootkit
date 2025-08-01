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

Node* addLL(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    Node* dummy = new Node(-1);
    Node* current = dummy;
    int carry = 0;
    int sum = 0;
    while(t1 != nullptr || t2 != nullptr){
        sum = carry;
        if(t1) sum = sum + t1->data;
        if(t2) sum = sum + t2->data;
        carry = sum / 10;
        sum = sum % 10;
        Node* newNode = new Node(sum);
        current->next = newNode;
        current = current->next;
        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        current->next = newNode;
    }
    return dummy->next;
}

int main(){
    vector<int> nums1 = {3, 5};
    vector<int> nums2 = {4, 5, 9, 9};
    Node* head1 = convertToLL(nums1);
    Node* head2 = convertToLL(nums2);
    // head = brute(head);
    Node* head3 = addLL(head1, head2);
    display(head3);
    return 0;
}