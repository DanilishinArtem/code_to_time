

class Solution:
    @staticmethod
    def isValid(s: str) -> bool:
        stack = []
        closeToOpen = {")": "(", "}": "{", "]": "["}
        for c in s:
            if c in closeToOpen:
                if stack and stack[-1] == closeToOpen[c]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(c)
        return not stack


if __name__ == "__main__":
    s = "([{}])"
    print(Solution.isValid(s))
