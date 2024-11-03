int find(vector<int>& arr, int maxPages) {
    int students = 1;  // Start with the first student
    long long pagesStudent = 0;  // Track the pages assigned to the current student

    for (int i = 0; i < arr.size(); i++) {
        if (pagesStudent + arr[i] <= maxPages) {
            pagesStudent += arr[i];  // Assign current board to the current student
        } else {
            students++;  // Allocate a new student
            pagesStudent = arr[i];  // Start counting pages for the new student
        }
    }

    return students;  // Return the number of students needed
}

int findLargestMinDistance(vector<int>& boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    while (low <= high) {
        int mid = (low + high) / 2;
        int students = find(boards, mid);

        if (students > k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}
