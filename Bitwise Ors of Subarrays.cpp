class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> cur;

        for (int x : arr) {
            unordered_set<int> next;

            // Subarray containing only x
            next.insert(x);

            // Extend all previous subarrays by x
            for (int val : cur) {
                next.insert(val | x);
            }

            // Add all results to the final answer
            for (int val : next) {
                ans.insert(val);
            }

            cur = next;
        }

        return ans.size();
    }
};