#include <iostream>
#include <vector>
#include <climits>  // For INT_MIN
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        // First pass: Find potential candidates for majority elements
        for (int i = 0; i < nums.size(); i++) {
            if (cnt1 == 0 && el2 != nums[i]) {
                cnt1 = 1;
                el1 = nums[i];
            } else if (cnt2 == 0 && el1 != nums[i]) {
                cnt2 = 1;
                el2 = nums[i];
            } else if (el1 == nums[i]) {
                cnt1++;
            } else if (el2 == nums[i]) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        // Second pass: Validate candidates
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (el1 == nums[i]) cnt1++;
            if (el2 == nums[i]) cnt2++;
        }

        // Prepare the result
        vector<int> ls;
        if (cnt1 > nums.size() / 3) ls.push_back(el1);
        if (cnt2 > nums.size() / 3) ls.push_back(el2);

        return ls;
    }
};

int main() {
    // Example usage
    Solution sol;
    vector<int> nums = {3, 2, 3, 1, 1, 2, 2};
    vector<int> result = sol.majorityElement(nums);

    // Output the result
    cout << "Majority elements are: ";
    for (int el : result) {
        cout << el << " ";
    }
    cout << endl;

    return 0;
}
