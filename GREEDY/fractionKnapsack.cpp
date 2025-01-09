
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<double, int>> items;
        for (int i = 0; i < val.size(); i++) 
            items.push_back({(double)val[i] / wt[i], i});

        sort(items.rbegin(), items.rend());

        double totVal = 0;
        for (auto& item : items) {
            int idx = item.second;
            if (wt[idx] <= capacity) {
                totVal += val[idx];
                capacity -= wt[idx];
            } else {
                totVal += item.first * capacity;
                break;
            }
        }
        return totVal;
    }
};
