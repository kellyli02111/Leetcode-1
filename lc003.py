class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        start = 0
        end = 0
        myDict = {}
        res = 0
        n = len(s)
        if(s == ""):
            return 0
        while(end < n):
            if(myDict.get(s[end]) != None):
                del myDict[s[start]]
                start = start + 1
            else:
                myDict[s[end]] = 1
                end = end + 1
                res = max(res, (end - start))
        return res
            
