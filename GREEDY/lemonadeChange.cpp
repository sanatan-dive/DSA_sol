
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count_five = 0; 
        int count_ten = 0;  

        for (int bill : bills) {
            if (bill == 5) {
                count_five++; 
            } else if (bill == 10) {
                if (count_five > 0) {
                    count_five--; 
                    count_ten++; 
                } else {
                    return false; 
                }
            } else { 
                if (count_ten > 0 && count_five > 0) {
                    count_ten--; 
                    count_five--; 
                } else if (count_five >= 3) {
                    count_five -= 3; 
                } else {
                    return false; 
                }
            }
        }

        return true; 
    }
};
