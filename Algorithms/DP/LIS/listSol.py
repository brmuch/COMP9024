from itertools import product
class Solution:
    """
    @param nums: An integer array
    @return: The length of LIS (longest increasing subsequence)
    """
    def longestIncreasingSubsequence(self, nums):
        # write your code here
        seqLs = []
        
        for num in nums:
            for ls in seqLs:
                if num > ls[-1]:
                    temp = list(ls)
                    temp.append(num)
                    seqLs.append(temp)
            seqLs.append([num])

                
        return max([len(i) for i in seqLs]) if len(seqLs) != 0 else 0