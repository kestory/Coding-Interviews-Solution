#计数所有数字出现的次数再找出超过一半的
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		// int hash[256] = {0};//这个256极有可能不够用，还是得用map
		map<int,int> hash;
		int n = numbers.size();

		for (int i = 0; i < n; i++)
			hash[numbers[i]]++;
		for (int i = 0; i < n; i++)
			if (hash[numbers[i]] > n / 2)
				return numbers[i];

		return 0;
	}
};



#使用STL的count函数
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int n = numbers.size();
		for (int i = 0; i < n; ++i)
			if (count(numbers.begin(), numbers.end(), numbers[i]) > n / 2)
				return numbers[i];

		return 0;
	}
};
