class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* zeroH = new Node(0);
        Node* oneH = new Node(0);
        Node* twoH = new Node(0);
        Node* zeroT = zeroH;
        Node* oneT = oneH;
        Node* twoT = twoH;
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == 0){
                zeroT->next = temp;
                zeroT = temp;
            }
            else if (temp->data == 1){
                oneT->next = temp;
                oneT = temp;
            }
            else{ 
                twoT->next = temp;
                twoT = temp;
            }
            temp = temp->next;
       
        }
        zeroT->next = (oneH->next)?oneH->next:twoH->next;
        oneT->next = (twoH->next)?twoH->next:NULL;
        twoT->next = NULL;
        return zeroH->next;
    }
};  