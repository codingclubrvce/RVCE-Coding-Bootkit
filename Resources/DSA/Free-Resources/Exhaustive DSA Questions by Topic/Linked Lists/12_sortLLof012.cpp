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
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;
    while(temp != nullptr){
        if(temp->data == 0){
            c0++;
        }
        else if(temp->data == 1){
            c1++;
        }
        else if(temp->data == 2){
            c2++;
        }
        temp = temp->next;
    }
    temp = head;
    while(c0){
        temp->data = 0;
        temp = temp->next;
        c0--;
    }
    while(c1){
        temp->data = 1;
        temp = temp->next;
        c1--;
    }
    while(c2){
        temp->data = 2;
        temp = temp->next;
        c2--;
    }
    return head;
}

Node* optimal(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    Node* temp = head;
    Node* dummyZero = new Node(-1);
    Node* dummyOne = new Node(-1);
    Node* dummyTwo = new Node(-1);
    Node* zero = dummyZero;
    Node* one = dummyOne;
    Node* two = dummyTwo;
    while(temp != nullptr){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }
        if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }
        if(temp->data == 2){
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    if(dummyOne->next != nullptr){
        zero->next = dummyOne->next;
    }
    else{
        zero->next = dummyTwo->next;
    }
    one->next = dummyTwo->next;
    two->next = nullptr;
    head = dummyZero->next;
    delete dummyZero;
    delete dummyOne;
    delete dummyTwo;
    return head;
}

int main(){
    vector<int> nums = {1, 2, 1, 2, 1};
    Node* head = convertToLL(nums);
    display(head);
    // head = brute(head);
    head = optimal(head);
    display(head);
    return 0;
}