#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

typedef node ND;

// Global head pointer
ND* head = nullptr;

void beginInsert(int item) {
    ND* ptr = new ND; // Allocate memory using new

    if (ptr == nullptr) {
        cout << "Overflow" << endl;
        return;
    }

    ptr->data = item;

    if (head == nullptr) {  // If list is empty
        head = ptr;
        head->next = head;  // Point to itself to make circular
    } else {
        ND* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        ptr->next = head;   // New node points to head
        temp->next = ptr;   // Last node points to new node
        head = ptr;         // Update head
    }

    cout << "Node inserted at the beginning with value: " << ptr->data << endl;
}

void lastInsert(int val) {
    ND* newNode = new ND;  // Create a new node
    newNode->data = val;

    if (head == nullptr) {  // If the list is empty
        head = newNode;
        head->next = head;  // Make it circular by pointing to itself
        cout << "Node inserted as the only element with value: " << val << endl;
        return;
    }

    ND* temp = head;
    while (temp->next != head) {  // Traverse to the last node
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;  // Point back to head to maintain circular structure
    cout << "Node inserted at the end with value: " << newNode->data << endl;
}

void randomInsert(int item, int loc) {
    ND* ptr = new ND;

    if (ptr == nullptr) {
        cout << "Overflow" << endl;
        return;
    }

    ptr->data = item;

    if (head == nullptr) {  // If list is empty
        cout << "List is empty, inserting at the beginning." << endl;
        ptr->next = ptr;  // Point to itself to make circular
        head = ptr;
        cout << "Node inserted with value: " << ptr->data << endl;
        return;
    }

    if (loc == 0) {  // Insert at the beginning
        ND* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        ptr->next = head;
        temp->next = ptr;
        head = ptr;
        cout << "Node inserted at location 0 with value: " << item << endl;
        return;
    }

    ND* temp = head;
    for (int i = 0; i < loc - 1; i++) {
        if (temp->next == head) {  // Circular condition check
            cout << "Location out of bounds, can't insert." << endl;
            delete ptr; // Clean up allocated memory
            return;
        }
        temp = temp->next;
    }

    ptr->next = temp->next;
    temp->next = ptr;
    cout << "Node inserted with value: " << ptr->data << " at location: " << loc << endl;
}

void beginDelete() {
    if (head == nullptr) {
        cout << "\nList is empty\n";
        return;
    }

    if (head->next == head) {  // Only one node in the list
        delete head;
        head = nullptr;
        cout << "\nOnly node of the list deleted ...\n";
        return;
    }

    ND* ptr = head;
    ND* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    head = head->next;
    temp->next = head;  // Last node points to new head
    delete ptr; // Correctly deallocate memory
    cout << "\nNode deleted from the beginning ...\n";
}

void lastDelete() {
    if (head == nullptr) {
        cout << "\nList is empty" << endl;
        return;
    } 

    if (head->next == head) {  // Only one node in the list
        delete head;
        head = nullptr;
        cout << "\nOnly node of the list deleted ...\n";
        return;
    }

    ND* temp = head;
    while (temp->next->next != head) {  // Traverse to second last node
        temp = temp->next;
    }

    delete temp->next;  // Delete the last node
    temp->next = head;  // Update the new last node to point to head
    cout << "\nDeleted Node from the last ...\n";
}

ND* kdelete(ND* head, int el) {
    if (head == nullptr) return head;

    ND* ptr = head;
    ND* prev = nullptr;

    // Special case: head node contains the element
    if (head->data == el) {
        if (head->next == head) {  // Only one element in the list
            delete head;
            return nullptr;
        }

        ND* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
        delete ptr;
        return head;
    }

    do {
        prev = ptr;
        ptr = ptr->next;
    } while (ptr != head && ptr->data != el);

    if (ptr->data == el) {
        prev->next = ptr->next;
        delete ptr;
    }

    return head;
}

ND* search(ND* head, int val) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return head;
    }

    ND* ptr = head;
    int count = 0;
    bool found = false;

    do {
        if (ptr->data == val) {
            cout << "Found " << ptr->data << " at position " << count << endl;
            found = true;
        }
        ptr = ptr->next;
        count++;
    } while (ptr != head);

    if (!found) cout << "Element " << val << " not found in the list." << endl;
    return head;
}

void traverseList() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    ND* ptr = head;
    cout << "List contents: ";
    do {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << endl;
}

int main() {
    beginInsert(1);  // Insert at the beginning
    lastInsert(2);   // Insert at the end
    randomInsert(4, 0); // Insert at the beginning (again)
    traverseList();
    search(head, 2);

    // Clean up allocated memory
    ND* temp;
    while (head != nullptr && head->next != head) {
        temp = head;
        head = head->next;
        delete temp;
    }
    delete head; // Delete the last remaining node if any

    return 0;
}
