 #include <bits/stdc++.h> 
#include <cstddef>
 using namespace std:

   class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

     while(fast!= NULL && fast->next != NULL ){
       slow = slow->next;
       fast = fast->next->next;

     }
     return slow;

   }
};
