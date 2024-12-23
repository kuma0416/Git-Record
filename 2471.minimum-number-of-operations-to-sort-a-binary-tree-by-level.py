# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        t = deque([])
        t.appendleft([root])
        tcount = deque([])
        tmp = root.left is not None or root.right is not None
        while tmp == True:
            el = []
            heapq.heapify(el)
            count = 0
            tel = []
            for n in t[-1]:
                if n.left is not None:
                    tel.append(n.left)
                    heapq.heappush(el, [n.left.val, count])
                    count += 1
                if n.right is not None:
                    tel.append(n.right)
                    heapq.heappush(el, [n.right.val, count])
                    count += 1
            if count == 0:
                tmp = False
            else:
                t.append(tel)
                tcount.append(el)

        t1Len = len(tcount)
        res = 0
        for i in range(t1Len):
            t2Len = len(tcount[i])
            mapping = dict()
            for j in range(t2Len):
                tu = heapq.heappop(tcount[i])
                tmpj = tu[1]
                # this part can be improved
                while tmpj in mapping:
                    tmpj = mapping[tmpj]
                if tmpj != j:
                    mapping[j] = tmpj
                    res += 1
        return res

# other person's solution
class Solution:
    def minimumOperations(self, root):
        if not root:
            return 0
        
        from collections import deque
        q = deque([root])
        operations = 0

        while q:
            size = len(q)
            level = []

            for _ in range(size):
                node = q.popleft()
                level.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

            sort_level = sorted(level)
            mp = {v: i for i, v in enumerate(level)}

            for i in range(len(level)):
                while level[i] != sort_level[i]:
                    operations += 1
                    cur = mp[sort_level[i]]
                    mp[level[i]] = cur
                    level[i], level[cur] = level[cur], level[i]

        return operations