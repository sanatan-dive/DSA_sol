class Solution {

  public:
 
int minCoins(vector<int>& coins, int sum) {
    int n = coins.size();
    vector<int> dp(sum + 1, INT_MAX); // DP array to store minimum coins for each value
    dp[0] = 0; // Base case: 0 coins needed for sum 0

    for (int i = 1; i <= sum; i++) {
        for (int coin : coins) {
            if (i >= coin && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[sum] == INT_MAX ? -1 : dp[sum];
}
};
