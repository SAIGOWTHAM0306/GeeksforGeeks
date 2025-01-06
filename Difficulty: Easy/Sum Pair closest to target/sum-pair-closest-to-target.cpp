//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        if (arr.size() < 2) {
        return {};
    }

    // Sort the array
    sort(arr.begin(), arr.end());

    // Initialize two pointers
    int left = 0, right = arr.size() - 1;

    // Variables to store the best pair and the closest difference
    vector<int> closestPair;
    int closestDiff = INT_MAX;
    int maxAbsDiff = INT_MIN;

    while (left < right) {
        // Calculate the current sum
        int currentSum = arr[left] + arr[right];

        // Calculate the difference from the target
        int diff = abs(currentSum - target);

        // Check if this pair is closer or has a larger absolute difference
        if (diff < closestDiff || (diff == closestDiff && abs(arr[right] - arr[left]) > maxAbsDiff)) {
            closestPair = {arr[left], arr[right]};
            closestDiff = diff;
            maxAbsDiff = abs(arr[right] - arr[left]);
        }

        // Move the pointers
        if (currentSum < target) {
            left++;
        } else {
            right--;
        }
    }

    return closestPair;
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
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends