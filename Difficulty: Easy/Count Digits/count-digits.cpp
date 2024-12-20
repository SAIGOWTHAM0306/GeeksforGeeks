//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        int original = n; // Store the original number
    int count = 0;    // Counter for digits that divide n

    while (n > 0) {
        int digit = n % 10; // Extract the last digit
        n /= 10;            // Remove the last digit

        // Check if the digit is non-zero and divides the original number
        if (digit != 0 && original % digit == 0) {
            count++;
        }
    }

    return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends