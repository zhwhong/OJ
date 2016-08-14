class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return
        n = len(s)
        if n == 1:
            return s

        ret = s[0]
        for i in xrange(0, n):
            cur = self.get_palindrome_from_center(s, i, i)  # odd length
            if len(cur) > len(ret):
                ret = cur
            cur = self.get_palindrome_from_center(s, i, i+1)
            if len(cur) > len(ret):
                ret = cur
        return ret

    def get_palindrome_from_center(self, s, begin, end):
        while begin >= 0 and end < len(s) and s[begin] == s[end]:
            begin -= 1
            end += 1

        return s[begin+1: end-1+1]
