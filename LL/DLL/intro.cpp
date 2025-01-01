#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;

    // Constructor
    Node(int val) {
        data = val;
        next = NULL;
        back = NULL;
    }
};

// Function to convert an array to a doubly linked list
Node* convertArr2DLL(vector<int> arr) {
    if (arr.empty()) return NULL; // Handle empty array case

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }

    return head;
}

Node* deleteHead(Node* head) {
    if (head == NULL) return NULL;

    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* prev = head;
    head = head->next;
    head->back = NULL;
    prev->next = NULL;
    delete prev;

    return head;
}

Node* deleteTail(Node* head) {
    if (head == NULL) return NULL;

    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* prev = head;
    Node* temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    temp->back = NULL;
    prev->next = NULL;
    delete temp;

    return head;
}

Node* removeKthElement(Node* head, int k) {
    if (head == NULL) return NULL;

    int cnt = 1;
    Node* kNode = head;
    while (kNode != NULL) {
        if (cnt == k) break;
        cnt++;
        kNode = kNode->next;
    }

    if (kNode == NULL) return head; // k is out of bounds

    Node* prev = kNode->back;
    Node* front = kNode->next;

    if (prev == NULL && front == NULL) { // Only one node
        delete kNode;
        return NULL;
    } else if (prev == NULL) { // Deleting head
        front->back = NULL;
        delete kNode;
        return front;
    } else if (front == NULL) { // Deleting tail
        prev->next = NULL;
        delete kNode;
        return head;
    } else { // Deleting in between
        prev->next = front;
        front->back = prev;
        delete kNode;
        return head;
    }
}

Node* insertHead(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) return newNode;

    newNode->next = head;
    head->back = newNode;
    return newNode;
}

Node* insertTail(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->back = temp;
    return head;
}

Node* insertKth(Node* head, int val, int k) {
    Node* newNode = new Node(val);
    if (k == 1) return insertHead(head, val);

    Node* temp = head;
    int cnt = 1;
    while (temp != NULL && cnt < k - 1) {
        cnt++;
        temp = temp->next;
    }

    if (temp == NULL) return head; // k is out of bounds

    newNode->next = temp->next;
    newNode->back = temp;
    if (temp->next != NULL) {
        temp->next->back = newNode;
    }
    temp->next = newNode;

    return head;
}

// Utility function to print the doubly linked list
void printDLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int choice, val, k;

    do {
        cout << "\nMenu:\n";
        cout << "1. Convert Array to DLL\n";
        cout << "2. Insert at Head\n";
        cout << "3. Insert at Tail\n";
        cout << "4. Insert at Kth Position\n";
        cout << "5. Delete Head\n";
        cout << "6. Delete Tail\n";
        cout << "7. Remove Kth Element\n";
        cout << "8. Print DLL\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter the size of the array: ";
                int n;
                cin >> n;
                vector<int> arr(n);
                cout << "Enter the elements of the array: ";
                for (int i = 0; i < n; i++) cin >> arr[i];
                head = convertArr2DLL(arr);
                break;
            }
            case 2:
                cout << "Enter value to insert at head: ";
                cin >> val;
                head = insertHead(head, val);
                break;

            case 3:
                cout << "Enter value to insert at tail: ";
                cin >> val;
                head = insertTail(head, val);
                break;

            case 4:
                cout << "Enter value and position to insert: ";
                cin >> val >> k;
                head = insertKth(head, val, k);
                break;

            case 5:
                head = deleteHead(head);
                break;

            case 6:
                head = deleteTail(head);
                break;

            case 7:
                cout << "Enter position to remove: ";
                cin >> k;
                head = removeKthElement(head, k);
                break;

            case 8:
                printDLL(head);
                break;

            case 9:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 9);

    return 0;
}
