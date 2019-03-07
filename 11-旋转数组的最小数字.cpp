//找到第一个比它前序小的数，还是O(n)，也可以遍历找MIN
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int count = rotateArray.size();

		for (int i = 1; i < count; ++i)
		{
			if (rotateArray[i - 1] > rotateArray[i])
				return rotateArray[i];
		}
		// if(rotateArray[0]<rotateArray[count])
		return rotateArray[0];
	}
};



二分法，mid大于等于最前的，查找后半段；mid小于等于最后的，查找前半段。每次查找范围缩小一半。
然后要注意 l mid h 都相等的情况，最小值在前后半段都有可能
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int minNumberInRotateArray(vector<int> Array) {
		int l = 0, h = Array.size() - 1;
		if (Array.size() == 0) //题目提示说数组长度为0
			return 0;
		if (Array[l] < Array[h])//旋转了0个或者说没有旋转
			return Array[0];
		int mid = 0;
		while (Array[l] >= Array[h]) {
			if (h - l == 1) {
				return Array[h];
			}
			mid = (l + h) / 2;
			if (Array[h] == Array[l] && Array[mid] == Array[h]) {
				for (int i = l + 1; i < h; ++i)
				{
					if (Array[i - 1] > Array[i])
						return Array[i];
				}
				return Array[l];
			}

			if (Array[mid] >= Array[l])
				l = mid;
			else if (Array[mid] <= Array[h])
				h = mid;
		}
		return Array[mid];
	}
};


int main( )
{
	// int a[] = { 3, 4, 5, 1, 2};
	int a[] = { 1, 0, 1, 1, 1,};
	vector<int> vec(a, a + 5);

	Solution solu;
	cout << solu.minNumberInRotateArray(vec) << endl;

	return 0;
}
