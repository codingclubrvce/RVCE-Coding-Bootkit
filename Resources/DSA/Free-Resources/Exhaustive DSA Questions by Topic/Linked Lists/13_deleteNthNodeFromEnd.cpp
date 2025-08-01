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

Node* brute(Node* head, int n){
    Node* temp = head;
    int l = 0;
    while(temp != nullptr){
        l++;
        temp = temp->next;
    }
    if(n == l){
        // deleting the head case
        Node* newHead = head;
        newHead = head->next;
        delete head;
        return newHead;
    }
    temp = head;
    int curr = 0;
    while(temp != nullptr){
        curr++;
        if(l - curr == n){
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delNode->next = nullptr;
            delete delNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* optimal(Node* head, int n){
    Node* fast = head;
    Node* slow = head;
    while(n--){
        fast = fast->next;
    }
    if(fast == nullptr){
        Node* newHead = head;
        newHead = head->next;
        delete head;
        return newHead;
    }
    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    Node* delNode = slow->next;
    slow->next = delNode->next;
    delete delNode;
    return head;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    Node* head = convertToLL(nums);
    display(head);
    // head = brute(head, 5);
    head = optimal(head, 5);
    display(head);
    return 0;
}