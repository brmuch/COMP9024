class Solution:
    """
    @param nums: An integer array
    @return: The length of LIS (longest increasing subsequence)
    """
    def longestIncreasingSubsequence(self, nums):
        # write your code here
        seqLs = []
        
        for num in nums:
            if len(seqLs) == 0 or seqLs[-1] < num:
                seqLs.append(num)
                continue
                
            for i in range(len(seqLs)):
                if seqLs[i] > num:
                    seqLs[i] = num
                    break
                    
        return len(seqLs)