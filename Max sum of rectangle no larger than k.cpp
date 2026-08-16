class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = INT_MIN;

        // We want the smaller dimension to be used
        // for the pair of boundaries.
        if (m > n) {
            vector<vector<int>> transposed(n, vector<int>(m));

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    transposed[j][i] = matrix[i][j];
                }
            }

            matrix = transposed;
            swap(m, n);
        }

        // Fix left and right columns
        for (int left = 0; left < n; left++) {

            vector<int> rowSum(m, 0);

            for (int right = left; right < n; right++) {

                // Add current column to row sums
                for (int row = 0; row < m; row++) {
                    rowSum[row] += matrix[row][right];
                }

                // Find maximum subarray sum <= k
                set<int> prefixSet;
                prefixSet.insert(0);

                int prefixSum = 0;

                for (int sum : rowSum) {
                    prefixSum += sum;

                    // We need:
                    // prefixSum - previousPrefix <= k
                    //
                    // Therefore:
                    // previousPrefix >= prefixSum - k

                    auto it = prefixSet.lower_bound(prefixSum - k);

                    if (it != prefixSet.end()) {
                        ans = max(ans, prefixSum - *it);
                    }

                    prefixSet.insert(prefixSum);
                }
            }
        }

        return ans;
    }
};