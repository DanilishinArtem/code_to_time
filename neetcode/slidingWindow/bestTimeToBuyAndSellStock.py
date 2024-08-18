class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        minPrice = prices[0]
        profit = 0
        for price in prices:
            minPrice = min(minPrice, price)
            profit = max(profit, price - minPrice)
        return profit
    

if __name__ == "__main__":
    prices = [7,1,5,3,6,4]
    print(Solution().maxProfit(prices))