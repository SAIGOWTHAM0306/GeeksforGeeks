//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> changeBits(int N) {
        // code here
    int num_bits = 0;
    int temp = N;
    
    while (temp > 0) {
        num_bits++;
        temp >>= 1; 
    }
    
    
    int new_num = (1 << num_bits) - 1;
    
    
    int diff = new_num - N;
    
    
    return {diff, new_num};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        auto ans = ob.changeBits(N);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends