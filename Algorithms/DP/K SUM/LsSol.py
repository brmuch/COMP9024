class Solution:
    """
    @param A: An integer array
    @param k: A positive integer (k <= length(A))
    @param target: An integer
    @return: An integer
    """
    def kSum(self, A, k, target):
        # write your code here
        numDict, A = [None] * (target + 1), [i for i in A if i <= target]
    
        for a in A:
            for i in range(a, target + 1)[::-1]:
                if numDict[i] != None and numDict[i - a] != None:
                    numDict[i].extend([n + 1 for n in numDict[i - a] if n <= k - 1])
                elif numDict[i] == None and numDict[i - a] != None:
                    numDict[i] = [n + 1 for n in numDict[i - a] if n <= k - 1]
            if numDict[a] == None:
                numDict[a] = [1]
            else:
                numDict[a].append(1)
        return len([i for i in numDict[target] if i == k])