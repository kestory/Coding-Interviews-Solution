// 用1一位一位的去比较，n位的话总是n次
class Solution {
public:
	int  NumberOf1(int n) {
		int flag = 1, count = 0;
		while (flag != 0) {
			if ((n & flag) != 0)
				count++;

			flag = flag << 1;
		}
		return count;
	}
};
/*
n       : 10110100
n-1     : 10110011（10110100+11111111）
n&(n-1) : 10110000
n的最低位的1被消除了，这样有几个1就执行几次
*/
class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		while (n != 0) {//这里是 != 才能应对负数情况
			n = n & (n - 1);
			count++;
		}
		return count;
	}
};


#include <iostream>
#include <bitset>
using namespace std;
class Solution
{
public:
	int NumberOf1(int n)
	{
		bitset<32> bit(n);
		return bit.count();
	}

};

int main( )
{
	Solution solu;
	cout << solu.NumberOf1(9) << endl;;
	cout << solu.NumberOf1(-1) << endl;;
	cout << solu.NumberOf1(-2147483648) << endl;;

	return 0;
}
