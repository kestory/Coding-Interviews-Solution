# -*- coding:utf-8 -*-
class Solution:
    # 这里要特别注意~找到任意重复的一个值并赋值到duplication[0]
    # 函数返回True/False
    def duplicate(self, numbers, duplication):
        # write code here




# 使用count函数
class Solution:
    def duplicate(self, numbers, duplication):
    	for i in numbers:
    		if numbers.count(i)>1:
        		duplication[0]=i
        		return True
        return False


class Solution:
    def duplicate(self, numbers, duplication):
        numbers.sort()
        for i in range(len(numbers)-1):
        	if numbers[i]==numbers[i+1]:
        		duplication[0]=numbers[i]
        		return True
        return False



class Solution:
    def duplicate(self, numbers, duplication):
		flags = [False] * len(numbers)
        for i in range(len(numbers)):
            if flags[numbers[i]] == True:
                duplication[0] = numbers[i]
                return True
            flags[numbers[i]] = True
        return False
