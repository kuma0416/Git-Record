class Solution:
    # mine
    def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:
        ans = []
        vdict = dict()
        hLen = len(heights)
        refdict, orderdict = dict(), dict()

        def constructd(s, e):
            t = deque([s])
            for i in range(s, e):
                if heights[i] > heights[s]:
                    t.append(i)
            return t

        for a, b in queries:
            if a==b:
                # print(f"{a} {b} same")
                ans.append(a)
                continue
            
            if a>b:
                a, b = b, a
            if a not in refdict:
                t = constructd(a, hLen)
                refdict[a] = set(t)
                orderdict[a] = t
            if b not in refdict:
                t = constructd(b, hLen)
                refdict[b] = set(t)
                orderdict[b] = t

            vdbLen = len(orderdict[b])
            tf = False
            for i in range(vdbLen):
                if orderdict[b][i] in refdict[a]:
                    ans.append(orderdict[b][i])
                    tf = True
                    break

            if not tf:
                ans.append(-1)
        return ans
    # ref answer
class Solution:
    def leftmostBuildingQueries(self, heights, queries):
        n, q = len(heights), len(queries)
        result = [-1] * q
        deferred = [[] for _ in range(n)]
        pq = []

        for i in range(q):
            a, b = queries[i]
            if a > b:
                a, b = b, a
            if a == b or heights[a] < heights[b]:
                result[i] = b
            else:
                deferred[b].append((heights[a], i))

        for i in range(n):
            for query in deferred[i]:
                heapq.heappush(pq, query)
            while pq and pq[0][0] < heights[i]:
                result[pq[0][1]] = i
                heapq.heappop(pq)

        return result