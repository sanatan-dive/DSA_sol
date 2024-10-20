class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int len = 1;
        ListNode* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        k = k % len;
        if (k == 0) return head;

        int newTailIndex = len - k - 1;
        ListNode* newTail = head;
        for (int i = 0; i < newTailIndex; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        tail->next = head;

        return newHead;
    }
};
