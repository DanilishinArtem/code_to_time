import heapq
from collections import Counter
from collections import deque


class Solution:
    def leastInterval(self, tasks: list[str], n: int) -> int:
        count = Counter(tasks)
        maxHeap = [-cnt for cnt in count.values()]
        heapq.heapify(maxHeap)

        time = 0
        q = deque()
        while maxHeap or q:
            time += 1
            if maxHeap:
                cnt = 1 + heapq.heappop(maxHeap)
                if cnt:
                    q.append([cnt, time + n])

            if q and q[0][1] == time:
                cnt, _ = q.popleft()
                heapq.heappush(maxHeap, cnt)
        return time


if __name__ == "__main__":
    print(Solution().leastInterval(["A", "A", "A", "B", "B", "B"], 2))