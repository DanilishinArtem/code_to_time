# hashmap algo has a time complexity O(s + t) and a space complexity of O(s + t)

class Solution(object):
    def isAnagramHashmap(self, s, t):
        if len(s) != len(t):
            return False
        s_dict, t_dict = {}, {}
        for i in range(len(s)):
            s_dict[s[i]] = s_dict.get(s[i], 0) + 1
            t_dict[t[i]] = t_dict.get(t[i], 0) + 1
        return s_dict == t_dict

        