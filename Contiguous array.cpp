class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;

        // balance 0 occurs before the array starts
        mp[0] = -1;

        int balance = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0)
                balance--;
            else
                balance++;

            // Same balance means equal 0s and 1s
            if (mp.find(balance) != mp.end()) {
                maxLen = max(maxLen, i - mp[balance]);
            }
            else {
                mp[balance] = i;
            }
        }

        return maxLen;
    }
};