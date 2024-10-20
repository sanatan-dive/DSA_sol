class Solution {
public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Pointer to the head of the list
        Node* current = *head_ref;
        Node* prev = nullptr;

        // Deleting nodes at the beginning with value x
        while (current != nullptr && current->data == x) {
            Node* temp = current;
            current = current->next;
            delete temp;  // Free memory of the deleted node
        }
        *head_ref = current;  // Update the head pointer

        // Traverse the rest of the list
        while (current != nullptr) {
            // Check for nodes with value x
            if (current->data == x) {
                Node* temp = current;
                current = current->next;
                if (prev != nullptr) {
                    prev->next = current;  // Skip the node with value x
                }
                delete temp;  // Free memory of the deleted node
            } else {
                // Move to the next node
                prev = current;
                current = current->next;
            }
        }
    }
};
