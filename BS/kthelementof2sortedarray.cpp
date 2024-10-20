#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size(), n = arr2.size();

    // Ensure arr1 is the smaller array
    if (m > n) return kthElement(k, arr2, arr1);

    int left = k;
    int low = max(0, k - n), high = min(k, m);

    // Apply binary search
    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;

        int l1 = (mid1 > 0) ? arr1[mid1 - 1] : INT_MIN;
        int l2 = (mid2 > 0) ? arr2[mid2 - 1] : INT_MIN;
        int r1 = (mid1 < m) ? arr1[mid1] : INT_MAX;
        int r2 = (mid2 < n) ? arr2[mid2] : INT_MAX;

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) {
            high = mid1 - 1;
        }
        else {
            low = mid1 + 1;
        }
    }

    return 0; // Dummy return; should never reach here
}
