# bruteforce has a time complexity of O(n^2) and a space complexity of O(1)
# hashmap has a time complexity of O(n) and a space complexity of O(n)

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashMap = {} # value : index
        for index, value in enumerate(nums):
            diff = target - value
            if diff in hashMap:
                return [hashMap[diff], index]
            else:
                hashMap[value] = index
        return {}