class Solution1(object):

    def getSum(self, a, b):
        MAX_INT = 0x7FFFFFFF
        MIN_INT = 0x80000000
        MASK = 0x100000000
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        while b != 0:
            a, b = (a^b) % MASK, ((a&b) << 1) % MASK
        return a if a < MAX_INT else (a % MIN_INT) - MIN_INT


class Solution2(object):
    MAX_INT = 0x7FFFFFFF
    MIN_INT = 0x80000000
    MASK = 0x100000000
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        if b == 0:
            return a if a < self.MAX_INT else (a % self.MIN_INT) - self.MIN_INT
        add_sum = (a^b) % self.MASK
        carry_in = ((a&b) << 1) % self.MASK
        return self.getSum(add_sum, carry_in)
