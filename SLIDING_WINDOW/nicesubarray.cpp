class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0, r = 0, oddCount = 0, result = 0, prefix = 0;

        while (r < nums.size()) {
            if (nums[r] % 2 != 0) {
                oddCount++;
                prefix = 0;
            }

            while (oddCount == k) {
                prefix++;
                if (nums[l] % 2 != 0) oddCount--;
                l++;
            }

            result += prefix;
            r++;
        }

        return result;
    }
};
