
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26] = {0};

        // Count the frequency of each letter in magazine
        for (char c : magazine) {
            freq[c - 'a']++;
        }

        // Check whether ransomNote can be constructed
        for (char c : ransomNote) {
            freq[c - 'a']--;

            if (freq[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};
