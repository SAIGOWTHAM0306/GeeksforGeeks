//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findSubArraySum(int k, vector<int> &arr) {
        // code here
        int count=0;
        int prefixSum[arr.size()];
        prefixSum[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            prefixSum[i]=prefixSum[i-1]+arr[i];
        }
        for(int i=0;i<arr.size();i++){
            for(int j=i;j<arr.size();j++){
                int sum=(i==0)?prefixSum[j]:prefixSum[j]-prefixSum[i-1];
                if(sum==k){
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.findSubArraySum(k, arr);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends