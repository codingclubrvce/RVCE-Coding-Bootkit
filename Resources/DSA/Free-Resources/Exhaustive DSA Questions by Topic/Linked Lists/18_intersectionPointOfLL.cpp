#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int num;
        Node* next;
        Node(int val) {
            num = val;
            next = NULL;
        }
};

int lengthOf(Node* x){
    Node* temp = x;
    int l = 0;
    while(temp != nullptr){
        l++;
        temp = temp->next;
    }
    return l;
}

void insertNode(Node* &head,int val) {
    Node* newNode = new Node(val);
    
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

//utility function to check presence of intersection
Node* brute(Node* head1, Node* head2){
    // hashing solution
    Node* t1 = head1;
    Node* t2 = head2;
    unordered_map<Node*, int> mpp;
    while(t1 != nullptr){
        mpp[t1]++;
        t1 = t1->next;
    }
    while(t2 != nullptr){
        mpp[t2]++;
        if(mpp[t2] == 2){
            return t2;
        }
        t2 = t2->next;
    }
    return nullptr;
}

Node* betterSolution(Node* h1, Node* h2, int length1, int length2){
    int diff = length1 - length2;
    Node* t1 = h1;
    Node* t2 = h2;
    while(diff--){
        t1 = t1->next;
    }
    while(t1 != nullptr && t2 != nullptr){
        if(t1 == t2){
            return t1;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    return nullptr;
}

Node* better(Node* head1, Node* head2){
    int l1 = lengthOf(head1);
    int l2 = lengthOf(head2);
    if(l1>l2){
        return betterSolution(head1, head2, l1, l2);
    }
    return betterSolution(head2, head1, l2, l1);
}

Node* optimal(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    while(t1 != t2){
        t1 = t1->next;
        t2 = t2->next;
        if(t1 == t2){
            return t1;
        }
        if(t1 == nullptr){
            t1 = head2;
        }
        if(t2 == nullptr){
            t2 = head1;
        }
    }
    return head1;
}

void printList(Node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    }
    cout<<head->num<<endl;
}

int main() {
    // creation of both lists 
    Node* head = NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    Node* head1 = head;
    head = head->next->next->next;
    Node* headSec = NULL;
    insertNode(headSec,3);
    Node* head2 = headSec;
    headSec->next = head;
    //printing of the lists
    cout<<"List1: "; printList(head1);
    cout<<"List2: "; printList(head2);
    //checking if intersection is present
    Node* answerNode = optimal(head1,head2);
    if(answerNode == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode->num<<endl;
    return 0;
}
