/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    Node* copyInBetween(Node* head){
        Node* temp = head;

        while(temp!=NULL){
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }

        return head;
    }

    Node* connectRandom(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* copyNode = temp->next;
            if(temp->random != NULL){
                copyNode->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        return head;
    }

    Node* getDeepCopy(Node* head){
        Node* dNode = new Node(-1);
        Node* temp = head;
        Node* res = dNode;

        while(temp != NULL){
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;

        }

        return dNode->next;
    }

    Node* copyRandomList(Node* head) {
        copyInBetween(head);
        connectRandom(head);
        return getDeepCopy(head);
    }
};