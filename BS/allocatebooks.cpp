int cntStu(vector<int> arr, int pages) {
    int students = 1;
    long long pagesStudetn = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (pagesStudetn + arr[i] <= pages) {
            pagesStudetn += arr[i];
        } else {
            students++;
            pagesStudetn = arr[i];
        }
    }
    return students;
    
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
   
    while(low<=high) {
        int mid = (low+high)/2;
        int students = cntStu(arr, mid);
        if(students<=m) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return low;
}