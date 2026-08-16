class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> ans;

        // Add original array
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(nums[i]);
        }

        // Add reverse of array
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans.push_back(nums[i]);
        }

        return ans;
    }
};