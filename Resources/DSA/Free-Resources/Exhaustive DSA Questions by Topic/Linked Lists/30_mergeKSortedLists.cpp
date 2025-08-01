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

Node* func(vector<vector<int>> arr){
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    // K * logK
    for(int i = 0; i<arr.size(); i++){
        Node* list = convertToLL(arr[i]);
        pq.push({list->data, list}); // logK
    }
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    // N * K
    while(!pq.empty()){
        auto p = pq.top();
        temp->next = p.second;
        pq.pop();
        if(p.second->next != nullptr){  
            pq.push({p.second->next->data, p.second->next}); // logK
        }
        temp = temp->next;
    }
    return dummy->next;
}

int main(){
    vector<vector<int>> arr = {{2, 5, 8, 10}, {1, 3, 3, 4, 10, 11, 14}, {3, 3, 4, 5, 6}};
    Node* list = func(arr);
    display(list);
    return 0;
}
