#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit) {
        int n = id.size();
        vector<pair<int, pair<int, int>>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], {deadline[i], id[i]}});
        }

        sort(jobs.rbegin(), jobs.rend());

        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        vector<bool> slot(maxDeadline + 1, false);

        int totalProfit = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            int currentDeadline = jobs[i].second.first;
            int currentProfit = jobs[i].first;
            int currentId = jobs[i].second.second;

            for (int j = currentDeadline; j > 0; j--) {
                if (!slot[j]) {
                    slot[j] = true;
                    totalProfit += currentProfit;
                    count++;
                    break;
                }
            }
        }

        return {count, totalProfit};
    }
};
