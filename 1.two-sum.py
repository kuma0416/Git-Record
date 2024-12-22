#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nLen = len(nums)
        mapping = dict()
        for i in range(nLen):
            if nums[i] in mapping:
                return [mapping[nums[i]], i]
            else:
                mapping[target-nums[i]] = i
print("hello world")
# @lc code=end

