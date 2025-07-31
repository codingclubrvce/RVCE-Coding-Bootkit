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

int lengthOfLL(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

bool searchElement(Node* head, int element){
    Node* temp = head;
    while(temp){
        if(temp->data == element){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertToLL(arr);
    Node* temp = head;
    while(temp){
        cout << temp->data << " -> " << temp->next << endl;
        temp = temp->next;
    }
    cout << "Length of Linked List: " << lengthOfLL(head) << endl;
    cout << "3 is present in the LL: " << searchElement(head, 3) << endl;
    cout << "7 is present in the LL: " << searchElement(head, 7) << endl;
}
