# logic of realization algo without using division operator:
    # through prefix and postfix arrays we can get product of all elements except self
    # source array: [1, 2, 3, 4]
    # prefix  array: [1, 1,  2,  6]
    # postfix array: [1, 4, 12, 24]
    # result = [24, 12, 8, 6]

    # For reduction of memory we can store prefix and postfix arrays in the result array



class Solution(object):
    # realization with using division operator:
    @staticmethod
    def productExceptSelfWithDivision(nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        result = [0] * len(nums)
        prod = 1
        zeros = 0
        index_zero = -1
        for index, item in enumerate(nums):
            if item == 0:
                zeros += 1
                index_zero = index
            else:
                prod *= item
                
        if zeros > 1:
            return result
        elif zeros == 1:
            result[index_zero] = prod
            return result
        else:
            for index, item in enumerate(nums):
                result[index] = int(prod / item)
            return result
        
    # realization without using division operator:
    @staticmethod
    def productExceptSelfWithoutDivision(nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        result = [1] * len(nums)
        # calculate prefix part and store it in the result array:
        for i in range(1, len(nums)):
            result[i] = result[i - 1] * nums[i - 1]
        postfix = 1
        for i in range(len(nums) - 1, -1, -1):
            result[i] = postfix * result[i]
            postfix *= nums[i]
        return result


if __name__ == "__main__":
    nums = [-1,1,1,-3,5]
    print("Original array: " + str(nums))
    print("Solution with division operator:" + str(Solution.productExceptSelfWithDivision(nums)))
    print("Solution without division operator: " + str(Solution.productExceptSelfWithoutDivision(nums)))