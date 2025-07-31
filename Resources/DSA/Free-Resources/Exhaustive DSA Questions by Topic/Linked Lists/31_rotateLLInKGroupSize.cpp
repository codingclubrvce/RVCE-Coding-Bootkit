#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
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
    if(arr.empty()) return nullptr;
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

Node* reverseLL(Node* head){
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

Node* findK(Node* head, int k){
    Node* temp = head;
    while(temp != nullptr && k > 0){
        k--;
        if(k == 0){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

Node* reverseK(Node* head, int k){
    if(head == nullptr) return nullptr;

    Node* temp = head;
    Node* prevNode = nullptr;

    while(temp != nullptr){
        Node* kthNode = findK(temp, k);
        if(kthNode == nullptr){
            if(prevNode != nullptr){
                prevNode->next = temp;
            }
            break;
        }
        Node* nextNode = kthNode->next;
        kthNode->next = nullptr;
        Node* reversedHead = reverseLL(temp);
        if(prevNode == nullptr){
            head = reversedHead;
        }
        else{
            prevNode->next = reversedHead;
        }
        prevNode = temp;
        temp = nextNode;
    }

    return head;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    Node* head = convertToLL(nums);
    cout << "Original List: ";
    display(head);
    head = reverseK(head, 2);
    cout << "Reversed in groups of 2: ";
    display(head);
    return 0;
}
