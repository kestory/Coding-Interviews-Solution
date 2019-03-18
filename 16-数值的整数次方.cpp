/*
考虑多种边界情况
指数为负数
base为0时都为0（0^0无意义，指数也不能为负）
*/
#include <iostream>

using namespace std;
class Solution {
public:
	double Power(double base, int exponent) {
		double re = 1; //指数为0，值为1
		if (base == 0) //基数为0
			return 0;
		if (exponent > 0) {
			for (int i = 0; i < exponent; ++i)
				re *= base;
			return re;
		}
		else if (exponent < 0) {
			for (int i = 0; i < -exponent; ++i)
				re *= base;
			return 1 / re;
		}
		else
			return re;
	}
};

int main(int argc, char *argv[]) {
	Solution solu;

	cout << solu.Power(2, 3) << endl;
	cout << solu.Power(2, -3) << endl;
	cout << solu.Power(2, 0) << endl;
	cout << solu.Power(0, -3) << endl;
	return 0;
}



// O(nlogn)的快速方法
//就是指数为正时可以加速，然后做成一个函数放到各种情况里
class Solution {
public:
	double Power_part(double base, int exponent) {

		if (exponent == 0)
			return 1;
		else if (exponent == 1)
			return base;

		double re = Power(base, exponent / 2);
		re = re * re;
//		if((exponent%2==1)||(exponent%2==-1))
		if ((exponent & 1) == 1)
			re = re * base;

		return re;
	}

	double Power(double base, int exponent) {
		double re = 1; //指数为0，值为1
		if (base == 0) //基数为0
			return 0;
		if (exponent > 0)
			return Power_part(base, exponent);
		else if (exponent < 0) {
			re =  Power_part(base, -exponent);
			return 1 / re;
		}
		else
			return re;
	}
};
