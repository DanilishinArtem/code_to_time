import heapq


class Solution:
    def lastStoneWeight(self, stones: list[int]) -> int:
       stones = [-x for x in stones]
       heapq.heapify(stones)
       while len(stones) > 1:
           first = -heapq.heappop(stones)
           second = -heapq.heappop(stones)
           if first > second:
               heapq.heappush(stones, second - first)
       stones.append(0)
       return abs(stones[0])


if __name__ == "__main__":
    stones = [2,7,4,1,8,1]
    print(Solution().lastStoneWeight(stones))