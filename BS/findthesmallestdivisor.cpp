class Solution {
public:
    int calculateDays(vector<int>& weights, int mid) {
        int days = 1;  // Start with one day
        int sum = 0;

        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if (sum > mid) {  // If sum exceeds the capacity, it counts as an additional day
                days++;
                sum = weights[i];  // Start the next day with the current weight
            }
        }

        return days;  // Return the total number of days needed
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());  // Min capacity is the max weight
        int high = accumulate(weights.begin(), weights.end(), 0);  // Max capacity is the sum of all weights

        while (low < high) {  // Binary search for the minimum capacity
            int mid = low + (high - low) / 2;
            if (calculateDays(weights, mid) <= days) {
                high = mid;  // Try for a smaller capacity
            } else {
                low = mid + 1;  // Increase capacity
            }
        }

        return low;  // Return the minimum capacity required to ship within the given days
    }
};
