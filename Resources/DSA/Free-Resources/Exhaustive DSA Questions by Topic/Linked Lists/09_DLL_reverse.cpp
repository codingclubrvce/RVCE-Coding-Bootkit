#include<bits/stdc++.h>
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

Node* brute(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp != nullptr){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

Node* optimal(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        prev = temp->back;
        temp->back = temp->next;
        temp->next = prev;
        temp = temp->back; // important
    }
    return prev->back; // IMPORTANT
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Node* head = convertToDLL(nums);
    display(head);
    // head = brute(head);
    head = optimal(head);
    display(head);
    return 0;
}