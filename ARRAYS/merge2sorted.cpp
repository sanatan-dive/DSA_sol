#include <vector>
#include <algorithm> // For std::sort if needed

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        // Initialize pointers for the last elements of each array
        int left = m - 1;  // Pointer for the last element in nums1
        int right = n - 1; // Pointer for the last element in nums2
        int index = m + n - 1; // Pointer for the last position in nums1

        // Merge nums2 into nums1 starting from the end
        while (left >= 0 && right >= 0) {
            if (nums1[left] > nums2[right]) {
                nums1[index--] = nums1[left--];
            } else {
                nums1[index--] = nums2[right--];
            }
        }

        // If there are remaining elements in nums2, copy them
        while (right >= 0) {
            nums1[index--] = nums2[right--];
        }

        // No need to copy remaining elements of nums1, they are already in place
    }
};
