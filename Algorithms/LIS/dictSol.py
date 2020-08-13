class Solution:
    """
    @param nums: An integer array
    @return: The length of LIS (longest increasing subsequence)
    """
    def longestIncreasingSubsequence(self, nums):
        # write your code here
        seqDict = dict(zip(range(1, len(nums)), [None for i in range(1, len(nums))]))
        
        for num in nums:
            ls = list([j for j in seqDict.values() if j != None])

            if len(ls) == 0:
                seqDict[1] = num
                continue
            elif ls[-1] < num:
                seqDict[len(ls) + 1] = num
                continue
                
            for i in range(len(ls)):
                if ls[i] > num:
                    seqDict[i + 1] = num
                    break
            
        return len([j for j in seqDict.values() if j != None])