# descriptioon: design an algorithm to encode a list of strings to a string. The encoded string
# is then sent over the network and is decoded back to the original list of strings.
# Please implement encode and decode

# Example:
# Input: ["lint","code","love","you"]
# Output: ["lint","code","love","you"]
# Explanation: One possible encode method is: "lint:;code:;love:;you"

# Here is realization like this:
# ["neet", "code"] ---> "4#neet4#code" ---> ["neet" , "code"]
# complexity: O(n)

class Solution:
    @staticmethod
    def encode(strs: list) -> str:
         result = ""
         for s in strs:
             result += str(len(s)) + "#" + s
         return result
    @staticmethod
    def decode(strs: str) -> list:
        result, i = [], 0
        while i < len(strs):
            j = i
            while j < len(strs) and strs[j] != "#":
                j += 1
            length = int(strs[i:j])
            result.append(strs[j + 1: j + 1 + length])
            i = j + 1 + length
        return result


if __name__ == "__main__":
    strs = ["neet", "code"]
    encode = Solution.encode(strs)
    decode = Solution.decode(encode)
    print("encoded string: " + encode)
    print("decoded string: " + str(decode))