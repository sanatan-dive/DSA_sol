#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
typedef struct Node nd;

//!function
nd* reverse_ll(nd* head){
    nd* temp = head;
    nd* prev = nullptr;

    while (temp != nullptr){
        nd* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
//! tc = o(n) and sc = o(1)