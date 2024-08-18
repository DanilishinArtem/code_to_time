import heapq


class Solution:
    def findKthLargestMySolution(self, nums: list[int], k: int) -> int:
        nums = [-x for x in nums]
        heapq.heapify(nums)
        result = []
        while k > 0:
            result.append(heapq.heappop(nums))
            k -= 1

        return -result[-1]
    
    def findKthLargest(self, nums: list[int], k: int) -> int:
        k = len(nums) - k
        def quickSelect(l, r):
            pivot, p = nums[r], l
            for i in range(l, r):
                if nums[i] <= pivot:
                    nums[p], nums[i] = nums[i], nums[p]
                    p += 1
            nums[p], nums[r] = nums[r], nums[p]
            if p > k:
                return quickSelect(l, p - 1)
            elif p < k:
                return quickSelect(p + 1, r)
            else:
                return nums[p]
        
        return quickSelect(0, len(nums) - 1)


if __name__ == "__main__":
    nums = [3, 2, 1, 5, 6, 4]
    k = 2
    print("\"My\" Solution:")
    print(Solution().findKthLargestMySolution(nums, k))
    print("\"Quick Select\" Solution:")
    print(Solution().findKthLargest(nums, k))