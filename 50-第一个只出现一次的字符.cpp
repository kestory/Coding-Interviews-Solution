#以ASCII码为键值
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		int hash[256] = {0}; //ASCII字符就256个
		// map<char, int> hash;
		for (int i = 0; i < str.size(); i++)
			hash[str[i]]++;
		for (int i = 0; i < str.size(); i++)
			if (hash[str[i]] == 1)
				return i;
		return -1;
	}
};
