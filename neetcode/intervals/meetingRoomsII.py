class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end


class Solution:
    def minMeetingRooms(self, intervals: list[Interval]) -> bool:
        start = sorted([x.start for x in intervals])
        end = sorted([x.end for x in intervals])

        res, count = 0, 0
        s, e = 0, 0
        while s < len(intervals):
            if start[s] < end[e]:
                count += 1
                s += 1
            else:
                count -= 1
                e += 1
            res = max(res, count)
        return res


if __name__ == "__main__":
    intervals = [Interval(0, 40), Interval(5, 10), Interval(15, 20)]
    # intervals = [Interval(0, 10), Interval(1, 3), Interval(2, 6), Interval(5, 8),Interval(7, 12), Interval(11, 15), Interval(13, 18), Interval(16, 20),Interval(19, 25), Interval(24, 30)]

    print("Solution:")
    print(Solution().minMeetingRooms(intervals))