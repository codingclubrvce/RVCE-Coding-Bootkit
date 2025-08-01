#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* back;
    // constructors
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
};

Node* convertToDLL(vector<int> &nums){
    Node* head = new Node(nums[0]);
    Node* prev = head;
    for(int i = 1; i<nums.size(); i++){
        Node* temp = new Node(nums[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
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

vector<pair<int, int>> brute(Node* head, int sum){
    vector<pair<int, int>> ans;
    Node* t1 = head;
    while(t1 != nullptr){
        Node* t2 = t1->next;
        while(t2 != nullptr && t1->data + t2->data <= sum){
            if(t1->data + t2->data == sum){
                ans.push_back({t1->data, t2->data});
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    return ans;
}

vector<pair<int, int>> optimal(Node* head, int sum){
    vector<pair<int, int>> ans;
    Node* l = head;
    Node* r = head;
    while(r->next != nullptr){
        r = r->next;
    }
    while(l->data < r->data){
        if(l->data + r->data == sum){
            ans.push_back({l->data, r->data});
            l = l->next;
            r = r->back;
        }
        else if(l->data + r->data < sum){
            l = l->next;
        }
        else{
            r = r->back;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 9};
    Node* head = convertToDLL(nums);
    display(head);
    // vector<pair<int, int>> ans = brute(head, 5);
    vector<pair<int, int>> ans = optimal(head, 5);
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}