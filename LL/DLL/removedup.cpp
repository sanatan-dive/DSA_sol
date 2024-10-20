class Solution
{
public:
    Node* removeDuplicates(struct Node* head)
    {
        Node* temp = head;
        while(temp != NULL && temp->next != NULL){
            Node* nextNode = temp->next;
            while(nextNode != NULL && nextNode->data == temp->data ){
                Node* delNode = nextNode;
                nextNode = nextNode->next;
                delete(delNode);
            }
            temp->next = nextNode;
            if(nextNode != NULL) nextNode->prev = temp;

            temp = temp->next;
        }
        return head;
    }
 
};
