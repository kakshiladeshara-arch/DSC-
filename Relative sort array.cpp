class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> freq(1001, 0);

        // Count frequency of elements in arr1
        for (int x : arr1) {
            freq[x]++;
        }

        vector<int> ans;

        // Add elements according to arr2 order
        for (int x : arr2) {
            while (freq[x] > 0) {
                ans.push_back(x);
                freq[x]--;
            }
        }

        // Add remaining elements in ascending order
        for (int x = 0; x <= 1000; x++) {
            while (freq[x] > 0) {
                ans.push_back(x);
                freq[x]--;
            }
        }

        return ans;
    }
};