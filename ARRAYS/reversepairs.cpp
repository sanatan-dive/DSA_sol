class Solution {
public:
    int cnt = 0;
  void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // Temporary array
        int left = low;   // Starting index of left half of arr
        int right = mid + 1; // Starting index of right half of arr

        // Storing elements in the temporary array in a sorted manner
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                // Count inversions: all remaining elements in left half are greater than arr[right]
                cnt += (mid - left + 1);
                right++;
            }
        }

        // If elements on the left half are still left
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // If elements on the right half are still left
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // Transferring all elements from temporary to arr
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);  // Sort left half
        mergeSort(arr, mid + 1, high); // Sort right half
        merge(arr, low, mid, high);  // Merge sorted halves
    }
     
     void countPairs(vector<int>& nums, int low , int high, int mid){ 
        int right = mid + 1;
        for(int i = low ; i <= mid ; i++){
            while(right<=high  && nums[i] > 2*nums[right]){
                right++;


            }
            cnt += (right - (mid + 1));
            
        }
         
     }

    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
    return cnt;
    }
};