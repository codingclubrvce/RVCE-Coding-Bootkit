#include<bits/stdc++.h>                                
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr) {};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *nextNode, Node *childNode) :
        data(x), next(nextNode), child(childNode) {}
};

Node* convertArrToLinkedList(vector<int>& arr){
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    for(int i = 0; i < arr.size(); i++){
        temp->child = new Node(arr[i]); 
        temp = temp->child; 
    }
    return dummyNode->child; 
}

Node* flattenLinkedListBruteForce(Node* head) {
    vector<int> arr;
    Node* temp = head;
    while(temp != nullptr){
        Node* trav = temp;
        while(trav != nullptr){
            arr.push_back(trav->data);
            trav = trav->child;
        }
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    return convertArrToLinkedList(arr);
}

Node* merge(Node* list1, Node* list2){
    Node* t1 = list1;
    Node* t2 = list2;
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(t1 != nullptr && t2 != nullptr){
        if(t1->data < t2->data){
            temp->child = t1;
            temp = t1;
            t1 = t1->child;
        }
        else{
            temp->child = t2;
            temp = t2;
            t2 = t2->child;
        }
        temp->next = nullptr;
    }
    if(t1) temp->child = t1;
    if(t2) temp->child = t2;
    if(dummy->child) dummy->child->next = nullptr;
    return dummy->child;
}

Node* recursive(Node* head){
    if(head == nullptr || head->next == nullptr){ // BASE CASE TO HANDLE SINGLE LIST
        return head;
    }

    Node* t1 = recursive(head->next);
    head = merge(head, t1);
    return head;
}

void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

void printOriginalLinkedList(Node* head, int depth) {
    while (head != nullptr) {
        cout << head->data;
        if (head->child) {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }
        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

int main() {
    Node* head = new Node(5);
    head->child = new Node(14);
    
    head->next = new Node(10);
    head->next->child = new Node(11);
    
    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(21);

    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);
    Node* flattened = recursive(head);
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}
                                
                            