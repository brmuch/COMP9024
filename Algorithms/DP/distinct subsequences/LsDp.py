class Solution:
    """
    @param S: A string
    @param T: A string
    @return: Count the number of distinct subsequences
    """
    def numDistinct(self, S, T):
        # write your code here
        if T == None or len(T) == 0:
            return 1

        subsequenceLs = [0] * (len(T))

        for c in S:
            for seq in range(0, len(subsequenceLs) - 1)[::-1]:
                if subsequenceLs[seq] > 0 and c == T[seq + 1]:
                    subsequenceLs[seq + 1] += subsequenceLs[seq]
            if c == T[0]:
                subsequenceLs[0] += 1
   
        return subsequenceLs[-1]