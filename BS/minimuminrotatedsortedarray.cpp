class Solution {
public:
 int search(vector<int>& nums, int target) {
        
        int low = 0;        
        int high = nums.size() - 1;
        int target = INT_MAX;
        int mid;
        while(low <= high){
             mid = low + (high - low)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] >= nums[low]){
                
            
         if(nums[mid] >= target && nums[low] <= target){
                target = nums[mid];
                high = mid - 1;
            }

            else{
                target = nums[mid];
                low = mid + 1;
            }
            }

            else{
            if(nums[mid] <= target && nums[high] >= target){
                low = mid + 1;
                target = nums[mid];
            }
            else{
                high = mid - 1;
                target = nums[mid];
            }
        }
        }
        return target;  
    int findMin(vector<int>& nums) {
        search(nums,target);

    }
};