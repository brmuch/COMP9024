class Solution:
    """
    @param m: An integer m denotes the size of a backpack
    @param A: Given n items with size A[i]
    @return: The maximum size
    """
    def backPack(self, m, A):
        # write your code here
        dicts = dict()
        
        return self.TopToBottomDP(m, A, dicts)
        
    
    def TopToBottomDP(self, m, A, dicts):
        A = [i for i in A if i <= m]
        if len(A) == 0 or m < min(A):
            return 0
        
        maxSize, resSize = 0, 0
        for item in A:
            if item < m:
                B = list(A)
                B.remove(item)
                
                if tuple(B) not in dicts.keys():
                    resSize = self.TopToBottomDP(m - item, B, dicts)
                else:
                    resSize = dicts[tuple(B)]
                
                maxSize = resSize + item if resSize + item > maxSize else maxSize
                
        dicts[tuple(A)] = maxSize
        
        return maxSize
            
            