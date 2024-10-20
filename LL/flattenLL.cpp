
class Solution {
  public:
    
    Node* merge(Node* list1,Node* list2){
    Node* dummy = new Node(-1);
    Node* res = dummy;

    while(list1 != NULL && list2 != NULL){
      if(list1->data < list2->data){
        res->child = list1;
        res = list1;
        list1 = list1->next;
      }
      else {
        res->child = list2;
        res = list2;
        list2 = list2->next;
      }
      if(list1) res->child = list1;
      else res->child = list2;

      if(dummy->child) dummy->child->next = nullptr;
      return dummy->child;
    }
  }
    Node *flatten(Node *root) {
      if(head == NULL || head->next == NULL) return head;

      Node* mergeHead = flatten(head->next);

      head = merge(head,mergeHead);
    return head;
    }
};

