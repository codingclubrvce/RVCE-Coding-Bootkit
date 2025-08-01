#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    // Constructor
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
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

Node* mergeLL(Node* list1, Node* list2){
    Node* t1 = list1;
    Node* t2 = list2;
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(t1 != nullptr && t2 != nullptr){
        if(t1->data < t2->data){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else{
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if(t1) temp->next = t1;
    if(t2) temp->next = t2;
    return dummy->next;
}

int main(){
    vector<int> arr1 = {2, 5, 8, 10};
    vector<int> arr2 = {1, 3, 3, 4, 10, 11, 14};
    Node* list1 = convertToLL(arr1);
    Node* list2 = convertToLL(arr2);
    Node* head = mergeLL(list1, list2);
    display(head);
    return 0;
}
