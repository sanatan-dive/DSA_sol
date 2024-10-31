class Solution {
   
   

    public:
     int power(int mid, int n, int m) {
        long long result = 1;
        for (int i = 1; i <=n; i++) {
            result *= mid;
            if (result > m) return 2; // Early exit if result exceeds limit
        }
        if(result == m) return 1;
        return 0;
    }
    int NthRoot(int n, int m) {
        int low = 1;
        int high = m;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long midPower = power(mid, n, m);

            if (midPower == 1) return mid;
            else if (midPower == 0) low = mid + 1;
            else high = mid - 1;
            
        }

        return -1;
    }
};