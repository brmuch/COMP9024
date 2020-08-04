class Solution:
    """
    @param m: An integer m denotes the size of a backpack
    @param A: Given n items with size A[i]
    @return: The maximum size
    """
    def backPack(self, m, A):
        # write your code here
        possibleVLS = {0}
    
        for item in A:
            temp = list(possibleVLS)
            possibleVLS = possibleVLS.union(set([i + item for i in temp if i + item <= m]))
    
        return max([i for i in list(possibleVLS) if i <= m])
                