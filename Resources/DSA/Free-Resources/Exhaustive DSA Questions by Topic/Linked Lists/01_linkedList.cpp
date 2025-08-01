#include<bits/stdc++.h>
using namespace std;

// Self defined data type
struct Node
{
    int data;
    Node *next;
    // Constructor
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};

int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* y = new Node(arr[0], nullptr);
    cout << y << endl; // 0x1a8f01016b0
    cout << y->data << endl; // 2
    cout << y->next << endl; // 0x0
    Node x = Node(arr[1], nullptr);
    // cout << x << endl; -> x is an object, hence it cannot be printed like this.
    cout << x.data << endl; // 5
    cout << x.next << endl; // 0x0
    return 0;
}
