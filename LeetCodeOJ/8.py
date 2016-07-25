class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        self.s = str.strip()
        num = 0
        if self.s != None and len(self.s) != 0:
            flag = 0
            minus = 1
            for i in self.s:
                if i == "+":
                    if flag == 0:
                        flag = 1
                    else:
                        break
                elif i == "-":
                    if flag == 0:
                        flag = 1
                        minus = -1
                    else:
                        break
                elif i >= '0' and i <= '9':
                    flag = 1
                    num = num * 10 + minus * int(i)
                else:
                    break
            
            if minus == 1 and num > 0x7FFFFFFF:
                num = 0x7FFFFFFF
            elif minus == -1 and (num < -0x80000000):
                num = -0x80000000
        return num
                    
        
