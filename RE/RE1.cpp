#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    // Complete this function
    int count = 1;
    int printNos(int N) {
        // Your code here
        if (count == N + 1) {
            return ;
        }
        cout << count << " ";
        count++;
        printNos(N);
    }
};

int main() {
    Solution s;
    cout << s.printNos(5) << endl;
    return 0;
}
