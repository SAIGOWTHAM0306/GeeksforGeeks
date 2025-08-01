class Solution {
  public:
    int getNetVowelConsonant(const string& s) {
    int count = 0;
    for (char ch : s) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            count += 1;
        else
            count -= 1;
    }
    return count;
}
    int countBalanced(vector<string>& arr) {
        // code here
        vector<int> diffs;
    for (const string& s : arr) {
        diffs.push_back(getNetVowelConsonant(s));
    }

    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1; // base case
    int prefixSum = 0;
    int balancedCount = 0;

    for (int diff : diffs) {
        prefixSum += diff;
        if (prefixCount.find(prefixSum) != prefixCount.end()) {
            balancedCount += prefixCount[prefixSum];
        }
        prefixCount[prefixSum]++;
    }

    return balancedCount;
    }
};