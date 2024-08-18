class Solution:
    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        index1 = 0
        index2 = len(numbers) - 1
        while index1 < index2:
            if target - numbers[index1] < numbers[index2]:
                index2 -= 1
            elif target - numbers[index1] > numbers[index2]:
                index1 += 1
            elif target - numbers[index1] == numbers[index2]:
                break
        if numbers[index1] + numbers[index2] == target:
            return [index1, index2]
        return [-1, -1]
        

if __name__ == "__main__":
    print(Solution().twoSum([2, 7, 11, 15], 9))