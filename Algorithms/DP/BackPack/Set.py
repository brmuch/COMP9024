class Solution:
    """
    @param m: An integer m denotes the size of a backpack
    @param A: Given n items with size A[i]
    @return: The maximum size
    """
    def backPack(self, m, A):
        # write your code here
        if sum(A) <= m:
            return sum(A)
        
        possibleVLS = {0}
        for item in A:
            temp = list(possibleVLS)
            temp.extend([i + item for i in temp if i + item <= m])
            
            if m in possibleVLS:
                return m
            possibleVLS = set(temp)
            
        return max(possibleVLS)
                