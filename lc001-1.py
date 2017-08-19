class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        res = []
        n = len(nums)
        for i in range(n):
            for j in range(i):
                if(nums[i] + nums[j] == target):
                    res = [i, j]
                    break
        return res
