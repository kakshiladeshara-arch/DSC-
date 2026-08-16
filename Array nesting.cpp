class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int maxCount = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] == -1)
                continue;

            int count = 0;
            int j = i;

            while (nums[j] != -1) {
                int next = nums[j];

                // Mark current element as visited
                nums[j] = -1;

                j = next;
                count++;
            }

            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};