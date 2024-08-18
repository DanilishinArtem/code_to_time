import heapq


class MedianFinder:
    def __init__(self):
        self.small, self.large = [], []        

    def addNum(self, num: int) -> None:
        heapq.heappush(self.small, -num)
        # make sure that every num "small" is <= every num "large"
        if (self.small and self.large and -self.small[0] > self.large[0]):
            val = -heapq.heappop(self.small)
            heapq.heappush(self.large, val)
        # uneven size?
        if (len(self.small) > len(self.large) + 1):
            val = -heapq.heappop(self.small)
            heapq.heappush(self.large, val)
        if (len(self.large) > len(self.small) + 1):
            val = heapq.heappop(self.large)
            heapq.heappush(self.small, -val)

    def findMedian(self) -> float:
        if len(self.small) > len(self.large):
            return -self.small[0]
        if len(self.large) > len(self.small):
            return self.large[0]
        return (-self.small[0] + self.large[0]) / 2


if __name__ == '__main__':
    medianFinder = MedianFinder()
    # medianFinder.addNum(1);    # arr = [1]
    # medianFinder.addNum(2);    # arr = [1, 2]
    # print(medianFinder.findMedian()); # return 1.5 (i.e., (1 + 2) / 2)
    # medianFinder.addNum(3);    # arr[1, 2, 3]
    # print(medianFinder.findMedian()); # return 2.0


    medianFinder.addNum(-1);
    print(medianFinder.findMedian());
    medianFinder.addNum(-2);
    print(medianFinder.findMedian());
    medianFinder.addNum(-3);
    print(medianFinder.findMedian());
