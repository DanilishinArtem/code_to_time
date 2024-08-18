# Space complexity O(n), Time complexity O(n)
# class Solution:
#     def trap(self, height: list[int]) -> int:
#         maxLeft = [0] * len(height)
#         maxRight = [0] * len(height)
#         for i in range(1, len(height)):
#             maxLeft[i] = max(maxLeft[i-1], height[i-1])
#         for i in range(len(height) - 2, -1, -1):
#             maxRight[i] = max(maxRight[i+1], height[i+1])
#         res = 0
#         for i in range(1, len(height) - 1):
#             res += max(min(maxLeft[i], maxRight[i]) - height[i], 0)
#         return res
    

# Space complexity O(1), Time complexity O(n)
class Solution:
    def trap(self, height: list[int]) -> int:
        if not height: return 0
        l, r = 0, len(height) - 1
        leftMax, rightMax = height[l], height[r]
        res = 0
        while l < r:
            if leftMax < rightMax:
                l += 1
                leftMax = max(leftMax, height[l])
                res += max(0, leftMax - height[l])
            else:
                r -= 1
                rightMax = max(rightMax, height[r])
                res += max(0, rightMax - height[r])
        return res
    

if __name__ == "__main__":
    height = [4,2,0,3,2,5]
    print(Solution().trap(height))