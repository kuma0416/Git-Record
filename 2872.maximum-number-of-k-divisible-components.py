class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        mat = [[-1 for _ in range(n)] for _ in range(n)]
        for i, j in edges:
            mat[i][j] = values[i]
            mat[j][i] = values[j]
            mat[i][i] = values[i]
            mat[j][j] = values[j]
        count = 0
        memo = dict()

        def countNum(f, t):
            key = str(f)+str(t)
            if key in memo:
                return memo[key]
            gt0C = 0
            for i in range(n):
                if mat[i][t] != -1:
                    gt0C += 1
                
            if gt0C == 2:
                memo[key] = values[t]
                return values[t]
            tsum = values[t]
            for i in range(n):
                if i != f and i != t and mat[i][t] != -1 :
                    tsum += countNum(t, i)
            memo[key] = tsum
            return tsum

        for i, ii in edges:
            if countNum(i, ii)%k == 0 and countNum(ii, i)%k == 0:
                count+=1
        
        return count+1