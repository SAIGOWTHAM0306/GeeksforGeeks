#User function Template for python3

class Solution:
    def findPosition(self, N):
        # code here 
        # Step 1: Check if N is 0, in that case return -1
        if N == 0:
            return -1
        
        # Step 2: Check if N has exactly one set bit
        if N & (N - 1) != 0:
            return -1
        
        # Step 3: Find the position of the only set bit
        position = 1  # Position starts at 1
        while N > 1:
            N = N >> 1
            position += 1
        
        return position


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N = int(input())
        
        ob = Solution()
        print(ob.findPosition(N))
# } Driver Code Ends