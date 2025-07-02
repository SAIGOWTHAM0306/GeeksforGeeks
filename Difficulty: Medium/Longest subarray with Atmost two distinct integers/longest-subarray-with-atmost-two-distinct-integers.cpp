class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        if (arr.empty()) return 0;
        
        int n = arr.size();
        int left = 0;
        int maxLength = 0;
        unordered_map<int, int> charCount; // Map to store frequency of elements
        
        for (int right = 0; right < n; right++) {
            // Add current element to the window
            charCount[arr[right]]++;
            
            // If we have more than 2 distinct integers, shrink window from left
            while (charCount.size() > 2) {
                charCount[arr[left]]--;
                if (charCount[arr[left]] == 0) {
                    charCount.erase(arr[left]);
                }
                left++;
            }
            
            // Update maximum length
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};