#include <iostream>
using namespace std;

// Node structure for a circular doubly linked list
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

// Deque structure using a circular doubly linked list
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

    // Function to insert an element at the front of the deque
    void q_insert_front(int item) {
        Node* newNode = new Node(item);  // Create a new node with the given item

        if (isEmpty()) {
            // If the deque is empty, initialize front and rear to the new node
            front = rear = newNode;
            front->next = front;  // Circular reference
            front->prev = front;  // Circular reference
        } else {
            // Insert the new node at the front
            newNode->next = front;  // Link the new node to the current front
            newNode->prev = rear;   // Link the new node to the current rear
            rear->next = newNode;   // Update rear's next to new front
            front->prev = newNode;  // Update current front's prev to new front
            front = newNode;        // Update front to the new node
        }

        size++;  // Increase the size of the deque
        cout << "Inserted " << item << " at the front of the deque." << endl;
    }

    // Function to insert an element at the rear of the deque
    void q_insert_rear(int item) {
        Node* newNode = new Node(item);  // Create a new node with the given item

        if (isEmpty()) {
            // If the deque is empty, initialize front and rear to the new node
            front = rear = newNode;
            front->next = front;  // Circular reference
            front->prev = front;  // Circular reference
        } else {
            // Insert the new node at the rear
            rear->next = newNode;  // Link the new node after rear
            newNode->prev = rear;  // Link back to the current rear
            newNode->next = front; // Circular link to the front
            front->prev = newNode; // Circular link from front back to new rear
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

        if (front == rear) {
            // If there's only one element in the deque
            front = rear = nullptr;  // Set both to null
        } else {
            // More than one element in the deque
            front = front->next;  // Update front to the next node
            front->prev = rear;   // Set the new front's prev to rear
            rear->next = front;   // Set rear's next to new front
        }

        delete temp;  // Free memory of the old front node
        size--;  // Decrease the size of the deque
        cout << "Deleted element from the front of the deque." << endl;
    }

    // Function to delete an element from the rear of the deque
    void q_delete_rear() {
        if (isEmpty()) {
            cout << "Deque is empty, nothing to delete from the rear." << endl;
            return;
        }

        Node* temp = rear;  // Node to be deleted

        if (front == rear) {
            // If there's only one element in the deque
            front = rear = nullptr;  // Set both to null
        } else {
            // More than one element in the deque
            rear = rear->prev;  // Update rear to the previous node
            rear->next = front; // Set rear's next to front
            front->prev = rear; // Set front's prev to new rear
        }

        delete temp;  // Free memory of the old rear node
        size--;  // Decrease the size of the deque
        cout << "Deleted element from the rear of the deque." << endl;
    }

    // Function to display the elements of the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }

        Node* current = front;
        cout << "Deque elements: ";
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != front);  // Loop back to the front

        cout << endl;
    }

    // Destructor to clean up memory
    ~Deque() {
        while (!isEmpty()) {
            q_delete_front();  // Use existing function to delete all nodes
        }
    }
};

int main() {
    Deque dq;  // Create a deque

    dq.q_insert_rear(10);  // Insert 10 at the rear
    dq.q_insert_rear(20);  // Insert 20 at the rear
    dq.q_insert_front(30); // Insert 30 at the front
    dq.q_insert_front(40); // Insert 40 at the front

    dq.display();  // Deque elements: 40 30 10 20

    dq.q_delete_front();  // Delete element from the front
    dq.display();  // Deque elements: 30 10 20

    dq.q_delete_rear();  // Delete element from the rear
    dq.display();  // Deque elements: 30 10

    dq.q_delete_front();  // Delete element from the front
    dq.q_delete_rear();   // Delete element from the rear
    dq.q_delete_front();  // Attempt to delete from an empty deque

    dq.display();  // Should display "Deque is empty."

    return 0;
}
