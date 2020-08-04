class Solution:
    """
    @param m: An integer m denotes the size of a backpack
    @param A: Given n items with size A[i]
    @return: The maximum size
    """
    def backPack(self, m, A):
            # write your code here
            wholeLs = [False] * sum(A)
            wholeLs.insert(0, True)
            
            if sum(A) <= m:
                return sum(A)
            
            for item in A:
                for j in range(item, sum(A) + 1)[::-1]:
                    if wholeLs[j - item]:
                        wholeLs[j] = True
            
            res = wholeLs[:m +1]
            return m - res[::-1].index(True)