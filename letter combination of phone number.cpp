class Solution {
public:
    vector<string> ans;

    void backtrack(string &digits, vector<string> &mp, int index, string current) {
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for (char ch : letters) {
            backtrack(digits, mp, index + 1, current + ch);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        backtrack(digits, mp, 0, "");

        return ans;
    }
};