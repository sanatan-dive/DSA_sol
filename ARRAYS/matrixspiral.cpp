#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralMatrix(vector<vector<int>>& MATRIX) {
    int n = MATRIX.size();
    int m = MATRIX[0].size();
    int left = 0, right = m - 1, top = 0, bottom = n - 1;

    vector<int> ans;

    while (top <= bottom && left <= right) {
        // Traverse from left to right across the top row
        for (int i = left; i <= right; i++) {
            ans.push_back(MATRIX[top][i]);
        }
        top++;

        // Traverse from top to bottom down the right column
        for (int i = top; i <= bottom; i++) {
            ans.push_back(MATRIX[i][right]);
        }
        right--;

        if (top <= bottom) {
            // Traverse from right to left across the bottom row
            for (int i = right; i >= left; i--) {
                ans.push_back(MATRIX[bottom][i]);
            }
            bottom--;
        }

        if (left <= right) {
            // Traverse from bottom to top up the left column
            for (int i = bottom; i >= top; i--) {
                ans.push_back(MATRIX[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> MATRIX = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};

    vector<int> result = spiralMatrix(MATRIX);

    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
