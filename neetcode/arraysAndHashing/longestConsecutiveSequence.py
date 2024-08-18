class Solution:
    @staticmethod
    def longestConsecutive(nums: list[int]) -> int:
        numSet = set(nums)
        Longest = 0
        for n in nums:
            if (n - 1) not in numSet:
                length = 0
                while (n + length) in numSet:
                    length += 1
                Longest = max(Longest, length)
        return Longest


if __name__ == "__main__":
    nums = [100, 4, 200, 1, 3, 2]
    print(Solution.longestConsecutive(nums))