class Solution {
  public:
    long long int floorSqrt(long long int n) {
        long long int low = 0;
        long long int high = n;
        int ans=0;
        // Your code goes here
        while(low<=high){
            long long int mid = low + (high-low)/2;
            if(mid*mid<=n){
                ans = mid;
                low = mid+1;
            }
            
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};