#include <vector>
using namespace std;

class Solution {
public:
    int rec(vector<int>& a, int k) {
        if (k < 0) return 0;
        int sum = 0, l = 0, r = 0;
        int ans = 0;

        while (r < a.size()) {
            sum += a[r];
            while (sum > k) {
                sum -= a[l];
                l++;
            }
            ans += (r - l + 1);
            r++;
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& a, int k) {
        return rec(a, k) - rec(a, k - 1);
    }
};
