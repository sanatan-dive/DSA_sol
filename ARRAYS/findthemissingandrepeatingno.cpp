class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here

        long long n = arr.size();
        long long Sn = (n*(n+1))/2;
        long long Sn2 = (n*(n+1)*(2*n+1))/6;

        long long S = 0;
        long long S2 = 0;

        for(int i = 0;i<n;i++){
            S +=arr[i];
             S2 += arr[i]*arr[i];
        }

        int val1 = Sn - S;
        int val2 = Sn2 - S2;
        val2=val2/val1;
        long long x = (val1+val2)/2;
        long long y = x - val1;

      
    }
};