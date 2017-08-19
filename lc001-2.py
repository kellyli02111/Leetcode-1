class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        res = []
        myDict = {}
        n = len(nums)
        for i in range(n):
            if(myDict.get(target - nums[i]) != None):
                res = [myDict[target - nums[i]], i]
                break
            else:
                myDict[nums[i]] = i
        return res
