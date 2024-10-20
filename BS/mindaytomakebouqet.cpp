class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int n = bloomDay.size();
        if (static_cast<long long>(m) * k > n) return -1; // Not enough flowers to make m bouquets

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        // Binary search for the minimum day
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canMakeBouquets(bloomDay, m, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

private:
    bool canMakeBouquets(const vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int flowers = 0;

        for (int bloom : bloomDay) {
            if (bloom <= day) {
                if (++flowers == k) {
                    bouquets++;
                    flowers = 0;
                    if (bouquets == m) return true; // Early return if enough bouquets are made
                }
            } else {
                flowers = 0;
            }
        }

        return bouquets >= m;
    }
};
