# hashmap and sorting algo has a time complexity of O(nlogn) and a space complexity of O(n)
# hashmap and maxK algo has a time complexity of O(klogn) and a space complexity of O(n)
# backet sort alho has a time complexity of O(n) and a space complexity of O(n)
    # table: number to frequency (problem: we should know that number is in range from 0 to 100)
    # |0|1|2|...|100|
    # |_|3|2|...|1__|

    # table: frequency to list of numbers (we bound hash table, because the frequency is in range from 1 to nums.size())
    # |0|__1__|_2_||_3_||4||5||6|
    # |_|[100]|[2]||[1]||4||5||6|
class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        count = {}
        frequency = [[] for i in range(len(nums) + 1)]

        for n in nums:
            count[n] = 1 + count.get(n, 0)
        for n, c in count.items():
            frequency[c].append(n)

        result = []
        for i in range(len(frequency) - 1, 0, -1):
            for n in frequency[i]:
                result.append(n)
                if len(result) == k:
                    return result

if __name__ == "__main__":
    nums = [1,1,1,2,2,3]
    k = 2
    print(Solution().topKFrequent(nums, k))
