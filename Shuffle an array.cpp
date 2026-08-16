class Solution {
private:
    vector<int> original;

public:
    Solution(vector<int>& nums) {
        original = nums;
    }

    vector<int> reset() {
        return original;
    }

    vector<int> shuffle() {
        vector<int> shuffled = original;

        for (int i = 0; i < shuffled.size(); i++) {
            int j = i + rand() % (shuffled.size() - i);

            swap(shuffled[i], shuffled[j]);
        }

        return shuffled;
    }
};