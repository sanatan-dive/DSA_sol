class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        sort(val.begin(),val.end());
        sort(wt.begin(),wt.end());
        
        int totVal = 0;

      for(int i = 0; i < wt.size();i++){
      if (wt[i]<=capacity){
        totVal += wt[i];
        capacity = capacity - wt[i];
      }
      else{
        
      }
    }
  }
};
