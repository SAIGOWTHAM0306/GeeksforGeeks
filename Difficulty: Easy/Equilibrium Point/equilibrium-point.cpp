//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
    int n=arr.size();
        // code here
    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += arr[i];
    }

    // Calculate left sum
    long long left_sum = 0; 
    for (int i = 0; i < n; i++) {
        // Calculate right sum
        long long right_sum = total_sum - left_sum - arr[i];

        // Check if equilibrium point is found
        if (left_sum == right_sum) {
            return i ; // 1-based indexing
        }

        // Update left sum
        left_sum += arr[i];
    }

    // If no equilibrium point is found
    return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends