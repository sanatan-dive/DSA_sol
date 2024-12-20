
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect if a cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // Cycle detected
                break;
            }
        }

        // If no cycle, return NULL
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }

        // Step 2: Find the start of the cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // Start of the cycle
    }
};

