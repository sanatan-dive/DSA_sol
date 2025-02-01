
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0, right = 0, max_count = 0, max_length = 0;

        while (right < s.size()) {
            freq[s[right] - 'A']++;
            max_count = max(max_count, freq[s[right] - 'A']);

            if ((right - left + 1 - max_count) > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            max_length = max(max_length, right - left + 1);
            right++;
        }

        return max_length;
    }
};
