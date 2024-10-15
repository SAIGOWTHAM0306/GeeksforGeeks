//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        // Your code here
        unordered_map<int, int> sum_map;
    
    // Initialize sum_map with sum 0 to handle subarrays that directly match target
    sum_map[0] = 1;
    
    int count = 0;   // To store the count of subarrays with sum equal to target
    int cum_sum = 0; // Cumulative sum
    
    // Traverse through the array
    for (int i = 0; i < arr.size(); i++) {
        // Add the current element to cumulative sum
        cum_sum += arr[i];
        
        // Check if (cum_sum - tar) is present in sum_map
        if (sum_map.find(cum_sum - tar) != sum_map.end()) {
            count += sum_map[cum_sum - tar];
        }
        
        // Add cum_sum to the map or update its frequency
        sum_map[cum_sum]++;
    }
    
    return count;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends