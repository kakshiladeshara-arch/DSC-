class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        vector<int> freq(101, 0);

        for (int x : nums) {
            freq[x]++;

            if (freq[x] > 2)
                return false;
        }

        return true;
    }
};