class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end


class Solution:
    def canAttendMeetings(self, intervals: list[Interval]) -> bool:
        intervals.sort(key=lambda x: x.start)

        for i in range(1, len(intervals)):
            interval1 = intervals[i - 1]
            interval2 = intervals[i]
            if interval1.end > interval2.start:
                return False

        return True


if __name__ == "__main__":
    intervals = [Interval(0, 30), Interval(5, 10), Interval(15, 20)]
    print("Solution:")
    print(Solution().canAttendMeetings(intervals))