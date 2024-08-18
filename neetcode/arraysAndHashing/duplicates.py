# brutforce algo has a time complexity of O(n^2) and a space complexity of O(1)
# sorting algo has a time complexity of O(nlogn) and a space complexity of O(1)
# hashset algo has a time complexity of O(n) and a space complexity of O(n)

class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        hashset = set()
        for item in nums:
            if item in hashset:
                return True
            else:
                hashset.add(item)
        return False