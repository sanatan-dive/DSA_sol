#include <iostream>
#include <vector>

using namespace std;
class Solution{   
public:
    bool helper( vector <int> a,int sum, int tempsum,int i){
    
    if(sum==tempsum){
        return true;
    }
    if(i>=a.size()){
        return false;
    }
    int reccall1= helper(a,sum,tempsum+a[i],i+1);
    int reccall2 = helper(a,sum,tempsum,i+1);
    return reccall1 || reccall2;}
    bool isSubsetSum(vector<int>arr, int sum){
        return helper(arr,sum,0,0);
    }
};

