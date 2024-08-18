import collections

class Solution:
    def maxSlidingWindow(self, nums: list[int], k: int) -> list[int]:
        output  = []
        q = collections.deque() # index
        l = r = 0
        while r < len(nums):
            # pop smaller values from the q
            while q and nums[q[-1]] < nums[r]:
                q.pop()
            q.append(r)
            if l > q[0]:
                q.popleft()
            if (r + 1) >= k:
                output.append(nums[q[0]])
                l += 1
            r += 1
        return output

        
if __name__ == "__main__":
    nums = [1,2,1,0,4,2,6]
    k = 3
    print(Solution().maxSlidingWindow(nums, k))