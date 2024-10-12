//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();

    // If the array has less than 2 elements, return -1
    if (n < 2) {
        return -1;
    }

    int max_sum = INT_MIN;

    // Traverse through the array to check adjacent pairs
    for (int i = 0; i < n - 1; ++i) {
        /*int first = arr[i];
        int second = arr[i + 1];*/

        // Compute the sum of the smallest and second smallest in this case
        //int current_sum = min(first, second) + max(first, second);
        int current_sum=arr[i]+arr[i+1];
        // Update max_sum if the current_sum is larger
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> a;
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        int res = obj.pairWithMaxSum(a);
        cout << res << endl;
    }
}
// } Driver Code Ends