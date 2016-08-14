class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sign = -1 if x < 0 else 1
        x *= sign

        # eliminated leading zero in the reversed integer
        while x:
            if x%10 == 0:
                x /= 10
            else:
                break

        # string manipulation
        x = str(x)
        lst = list(x)  # list('123') returns ['1', '2', '3']
        lst.reverse()
        x = "".join(lst)
        x = int(x)
        if x > 0x7FFFFFFF:
            x = 0
        return sign*x
