class Solution {
  public:
    int search(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        int count = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                // Count occurrences of target by expanding left and right
                count++; // Count the first found occurrence
                
                // Count all occurrences to the left
                int left = mid - 1;
                while (left >= 0 && arr[left] == target) {
                    count++;
                    left--;
                }
                
                // Count all occurrences to the right
                int right = mid + 1;
                while (right < arr.size() && arr[right] == target) {
                    count++;
                    right++;
                }
                
                break; // Exit after counting all occurrences
            } 
            else if (arr[mid] < target) {
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
        
        return count;
    }
    
    int count(vector<int>& arr, int target) {
        return search(arr, target);
    }
};