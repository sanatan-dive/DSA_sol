#include <iostream>
using namespace std;

// Node structure for a doubly linked list
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node
    Node* prev;     // Pointer to the previous node

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Deque structure using a doubly linked list
struct Deque {
    Node* front;  // Pointer to the front of the deque
    Node* rear;   // Pointer to the rear of the deque
    int size;     // Size of the deque

    // Constructor to initialize the deque
    Deque() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Function to check if the deque is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to insert an element at the rear of the deque
    void q_insert(int item) {
        Node* newNode = new Node(item);  // Create a new node with the given item

        if (isEmpty()) {
            // If the deque is empty, both front and rear point to the new node
            front = rear = newNode;
        } else {
            // Insert the new node at the rear
            rear->next = newNode;  // Link the new node after rear
            newNode->prev = rear;  // Link back to the current rear
            rear = newNode;        // Update rear to the new node
        }

        size++;  // Increase the size of the deque
        cout << "Inserted " << item << " at the rear of the deque." << endl;
    }

    // Function to delete an element from the front of the deque
    void q_delete_front() {
        if (isEmpty()) {
            cout << "Deque is empty, nothing to delete from the front." << endl;
            return;
        }

        Node* temp = front;  // Node to be deleted
        front = front->next;  // Update front to the next node

        if (front != nullptr) {
            front->prev = nullptr;  // If deque is not empty, set prev of new front to null
        } else {
            rear = nullptr;  // If deque is empty after deletion, set rear to null
        }

        delete temp;  // Free memory of the old front node
        size--;  // Decrease the size of the deque
        cout << "Deleted element from the front of the deque." << endl;
    }

    // Function to display the elements of the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }

        Node* current = front;
        cout << "Deque elements: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to clean up memory
    ~Deque() {
        while (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Deque dq;  // Create a deque

    dq.q_insert(10);  // Insert 10 at the rear
    dq.q_insert(20);  // Insert 20 at the rear
    dq.q_insert(30);  // Insert 30 at the rear
    dq.q_insert(40);  // Insert 40 at the rear

    dq.display();  // Deque elements: 10 20 30 40

    dq.q_delete_front();  // Delete element from the front
    dq.display();  // Deque elements: 20 30 40

    dq.q_delete_front();  // Delete element from the front
    dq.display();  // Deque elements: 30 40

    dq.q_delete_front();  // Delete element from the front
    dq.q_delete_front();  // Delete element from the front
    dq.q_delete_front();  // Attempt to delete from an empty deque

    dq.display();  // Should display "Deque is empty."

    return 0;
}
