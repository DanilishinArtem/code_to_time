class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        l, r = 0, 1
        maxLen = 0
        while r <= len(s):
            temp = s[l:r]
            if len(temp) == len(set(temp)):
                maxLen = max(maxLen, len(temp))
                r += 1
            else:
                l += 1
        return maxLen
    

if __name__ == "__main__":
    s = "abcabcbb"
    print(Solution().lengthOfLongestSubstring(s))
