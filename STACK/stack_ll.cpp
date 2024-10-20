#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

void isEmpty(Node* top){
    if (top == nullptr) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack is not empty.\n";
    }
}

// Function to push an element onto the stack
void push(Node*& top, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Function to pop an element from the stack
int pop(Node*& top) {
    if (top == nullptr) {
        return 0; // Underflow: Stack is empty
    }
    int value = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return value;
}

// Function to traverse the stack and reconstruct it
void traverse(Node*& S) {
    Node* temp = S;
    while (temp!= nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// Function to peek into the stack for a specific value
void peek(Node*& S, int PInfo) {
    Node* BS = nullptr; // Back Stack
    int Info;
    int flag = 0;

    // Step 2: Check/Get the returned information from POP
    while ((Info = pop(S)) != 0) {
        if (Info == PInfo) {
            cout << "Found: " << PInfo << "\n";
            flag = 1;
            break;
        }
        push(BS, Info);
    }
    if (!flag) {
        cout << "Element not found\n";
    }

    // Step 4: Reconstruct the Original Stack
    while (BS != nullptr) {
        Info = pop(BS);
        push(S, Info);
    }
}

int main() {
    Node* S = nullptr; // Original Stack
   isEmpty(S); //

    // Example usage
    push(S, 1);
    push(S, 2);
    push(S, 3);
    isEmpty(S);

    cout << "Stack before traversal and peek:\n";
    traverse(S);  // Outputs the stack in reverse order: 3 2 1
    

    cout << "Peek for element 2:\n";
    peek(S, 2);   // Output: Found: 2

    return 0;
}
