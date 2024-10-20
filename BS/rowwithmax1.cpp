class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        int n = arr.size();
        int m = arr[0].size();
        // code here
        
        int maxRowIndex = -1;      // Index of the row with the maximum 1s
        int j = m - 1;             // Start from the top-right corner

        for (int i = 0; i < n; i++) {
            // Move left while there are 1's in the row
            while (j >= 0 && arr[i][j] == 1) {
                j--;
                maxRowIndex = i;  // Update the row index with the most 1s
            }
        }

        return maxRowIndex;
    }
    
};