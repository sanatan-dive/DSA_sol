#include <bits/stdc++.h>
using namespace std;


int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    // Write Your Code Here
    // map <int,int> mpp;

    unordered_map <int,int> mpp;
    mpp[0] = 1;
    int presum = 0 ,cnt = 0;

    for(int i=0; i<arr.size(); i++){
        presum += arr[i];

        int remove = presum - k;

        cnt += mpp[remove];
        mpp[presum]++;
    }
    return cnt;
}

// yo wtf dude 103 ms
   