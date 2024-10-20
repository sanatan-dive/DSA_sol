class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
         Node* temp = head;

         while(temp->next != NULL){
            temp = temp->next;
         }
         vector<pair<int,int>> ans;
         Node* left = head;
         Node* right = temp;
         while(left->data<right->data ){
            if(left->data + right->data == target){
                ans.push_back({left->data,right->data});
                left = left->next;
                right = right->prev;
            }else if(left->data + right->data < target){
                left = left->next;
            }else{
                right = right->prev;
            }
         }
         return ans;
    }
};