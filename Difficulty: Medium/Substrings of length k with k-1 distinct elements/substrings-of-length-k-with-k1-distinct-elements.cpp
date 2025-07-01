class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        if (k > s.length()) return 0;

    unordered_map<char, int> charCount;
    int count = 0;
    int distinct = 0;

    for (int i = 0; i < s.length(); ++i) {
        // Add the current character to the window
        if (charCount[s[i]] == 0)
            ++distinct;
        ++charCount[s[i]];

        // Maintain window size
        if (i >= k) {
            char outgoing = s[i - k];
            --charCount[outgoing];
            if (charCount[outgoing] == 0) {
                charCount.erase(outgoing);
                --distinct;
            }
        }

        // Check if window has exactly k-1 distinct characters
        if (i >= k - 1 && distinct == k - 1)
            ++count;
    }

    return count;
    }
};