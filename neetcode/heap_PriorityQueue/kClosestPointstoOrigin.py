import heapq


class Solution:
    def kClosestMySolution(self, points: list[list[int]], k: int) -> list[list[int]]:
        hashMap = {}
        dists = []
        heapq.heapify(dists)

        for point in points:
            dist = point[0] ** 2 + point[1] ** 2
            if dist not in hashMap:
                hashMap[dist] = [point]
            else:
                hashMap[dist].append(point)
            heapq.heappush(dists, -dist)

            if len(dists) > k:
                dist = -heapq.heappop(dists)
                if len(hashMap[dist]) > 0:
                    hashMap[dist].pop()
        
        result = []
        while k > 0:
            dist = -heapq.heappop(dists)
            if len(hashMap[dist]) > 0:
                result.append(hashMap[dist].pop())
                k -= 1

        return result

    def kClosest(self, points: list[list[int]], k: int) -> list[list[int]]:
        minHeap = []
        for x, y in points:
            dist = (x**2) + (y**2)
            minHeap.append([dist, x, y])

        heapq.heapify(minHeap)
        result = []
        while k > 0:
            dist, x, y = heapq.heappop(minHeap)
            result.append([x, y])
            k -= 1

        return result


if __name__ == "__main__":
    s = Solution()
    print("My Solution:")
    print(s.kClosestMySolution([[1, 3], [-2, 2]], 1))
    print("NeetCode Solution:")
    print(s.kClosest([[1, 3], [-2, 2]], 1))
