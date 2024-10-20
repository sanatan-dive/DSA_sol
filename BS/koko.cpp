class Solution {
public:
    bool canEat(vector<int>& piles, int mid, int h){
        int hours = 0;
        for(int i = 0; i < piles.size(); i++){
            hours += (piles[i] + mid - 1)/mid;
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(canEat(piles, mid, h)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        

    }
};