#include <vector>
using namespace std;

class Solution {
public:
    int cnt = 0; // To count the inversions

    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // Temporary array
        int left = low;   // Starting index of left half of arr
        int right = mid + 1; // Starting index of right half of arr

        // Storing elements in the temporary array in a sorted manner
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                // Count inversions: all remaining elements in left half are greater than arr[right]
                cnt += (mid - left + 1);
                right++;
            }
        }

        // If elements on the left half are still left
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // If elements on the right half are still left
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // Transferring all elements from temporary to arr
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);  // Sort left half
        mergeSort(arr, mid + 1, high); // Sort right half
        merge(arr, low, mid, high);  // Merge sorted halves
    }

    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        mergeSort(arr, 0, n - 1); // Sort the array
        return cnt; // Return the count of inversions
    }
};
