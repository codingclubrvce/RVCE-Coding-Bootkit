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

void brute(Node* head){
    int l = 0;
    Node* temp = head;
    while(temp != nullptr){
        l++;
        temp = temp->next;
    }
    cout << "Length of Linked List: " << l << endl;
    temp = head;
    int c = 0;
    while(temp != nullptr){
        c++;
        if(c == (l/2)+1){
            cout << "The middle node is " << temp->data << endl;
            return;
        }
        temp = temp->next;
    }
    return;
}

void optimal(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "The middle node is " << slow->data << endl;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    Node* head = convertToLL(nums);
    brute(head);
    // optimal(head);
    return 0;
}