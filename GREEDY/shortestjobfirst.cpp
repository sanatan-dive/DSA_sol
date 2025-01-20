class Solution {
  public:
    long long solve(vector<int>& bt) {
      int n = bt.size();
       sort(bt.begin(),bt.end());
       int time = 0;
      int waitTime = 0;

    for(int item : bt){
      waitTime +=time;
      time += item;
    }
    return waitTime/n;
    }
};
