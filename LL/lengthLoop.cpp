class Solution {
  public:
    
    int countNodesinLoop(Node *head) {
        // Code here
        Node* slow = head;
        Node* fast = head;
        int count = 1;


        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
               
                break;
            }
        }
        
        if (fast == NULL || fast->next == NULL) {
            return 0;
        }

     
         while( slow->next != fast ){
             slow = slow->next;
             count++;
         }
         
         return count;
            
            
    }
};
