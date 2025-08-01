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

Node* reverse(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node* addOne(Node* head){
    head = reverse(head);
    int carry = 1;
    Node* temp = head;
    while(temp != nullptr){
        carry = carry + temp->data;
        temp->data = carry%10;
        carry = carry/10;
        if(carry == 0){
            break;
        }
        temp = temp->next;
    }
    head = reverse(head);
    if(carry == 1){
        Node* newNode = new Node(1, head);
        head = newNode;
    }
    return head;
}

int addOneOptimally(Node* temp){
    if(temp == nullptr){
        return 1;
    }
    int carry = addOneOptimally(temp->next);
    temp->data = temp->data + carry;
    if(temp->data < 10){
        return 0;
    }
    temp->data = 0;
    return 1;
}

Node* recursive(Node* head){
    int carry = addOneOptimally(head);
    if(carry == 1){
        Node* newNode = new Node(1, head);
        head = newNode;
    }
    return head;
}

int main(){
    vector<int> nums = {1, 5, 9, 9};
    Node* head = convertToLL(nums);
    // head = addOne(head);
    head = recursive(head);
    display(head);
    return 0;
}