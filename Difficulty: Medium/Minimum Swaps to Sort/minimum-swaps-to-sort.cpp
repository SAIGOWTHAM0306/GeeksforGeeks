//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        int n = arr.size();
    vector<pair<int, int>> paired(n);

    // Pair each element with its original index
    for (int i = 0; i < n; i++) {
        paired[i] = {arr[i], i};
    }

    // Sort the array based on the values
    sort(paired.begin(), paired.end());

    // Visited array to keep track of visited elements
    vector<bool> visited(n, false);
    int swaps = 0;

    // Traverse the array
    for (int i = 0; i < n; i++) {
        // If element is already visited or in the correct position
        if (visited[i] || paired[i].second == i) {
            continue;
        }

        // Cycle detection
        int cycle_size = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = true;
            j = paired[j].second; // Move to the next index in the cycle
            cycle_size++;
        }

        // Add the swaps required for the current cycle
        if (cycle_size > 1) {
            swaps += (cycle_size - 1);
        }
    }

    return swaps;
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
        Solution obj;
        cout << obj.minSwaps(arr) << endl;
    }
}

// } Driver Code Ends