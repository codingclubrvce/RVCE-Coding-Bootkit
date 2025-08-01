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

bool brute(Node* head){
    Node* temp = head;
    stack<int> st;
    while(temp != nullptr){
        st.push(temp->data);
    }
    temp = head;
    while(temp != nullptr){
        if(temp->data != st.top()){
            return false;
        }
        st.pop();
        temp = temp->next;
    }
    return true;
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

bool checkPalindrome(Node* head){
    // Step 1: Find middle of linked list
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    // Step 2: Reverse the second half
    Node* first = head;
    Node* newHead = reverse(slow->next);
    Node* second = newHead;
    // Step 3: Compare data values
    while(second != nullptr){
        if(first->data != second->data){
            reverse(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverse(newHead);
    return true;
}

int main(){
    vector<int> nums = {1, 2};
    Node* head = convertToLL(nums);
    display(head);
    if(checkPalindrome(head) == true){
        cout << "Palindrome Linked List\n";
    }
    else{
        cout << "Not a Palindrome Linked List\n";
    }
    return 0;
}