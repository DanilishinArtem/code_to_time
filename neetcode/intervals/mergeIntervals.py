class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        intervals.sort(key = lambda x: x[0])
        output = [intervals[0]]

        for start, end in intervals[1:]:
            lastEnd = output[-1][1]
            if start <= lastEnd:
                # case of overlapping
                output[-1][1] = max(lastEnd, end)
            else:
                output.append([start, end])

        return output


if __name__ == "__main__":
    s = Solution()
    print("Input:")
    input = [[1,3],[2,6],[8,10],[15,18]]
    print("intervals = " + str(input))
    print("Solution:")
    print(s.merge(input))