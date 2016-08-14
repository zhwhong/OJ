class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        length = len(s)
        matrix = [[] for _ in xrange(numRows)]

        i = 0
        while i < length:
            try:
                # going down
                for j in xrange(numRows):
                    matrix[j].append(s[i])
                    i += 1

                # going up
                for j in xrange(numRows-1-1, 0, -1):
                    matrix[j].append(s[i])
                    i += 1

            except IndexError:
                break

        lst = ["".join(element) for element in matrix]
        return "".join(lst)
