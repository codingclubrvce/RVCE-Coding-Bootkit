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

Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* list1, Node* list2){
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

Node* mergeSort(Node* head){
    if(head == nullptr || head->next == nullptr) // single element attainment case | BASE CASE
        return head;
    Node* middle = findMiddle(head);
    Node* lh = head;
    Node* rh = middle->next;
    middle->next = nullptr;

    lh = mergeSort(lh);
    rh = mergeSort(rh);

    return merge(lh, rh);
}

int main(){
    vector<int> nums = {3, 4, 2, 1, 5};
    Node* head = convertToLL(nums);
    display(head);
    head = mergeSort(head);
    display(head);
    return 0;
}