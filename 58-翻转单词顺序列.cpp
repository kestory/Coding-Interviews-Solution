用额外空间保存每个单词再填入
class Solution {
public:
	string ReverseSentence(string str) {
		str += " ";
		vector<string> token;
		int len = str.size();
		for (int i = 0; i < len; ++i)
		{
			int pos = str.find(" ", i); //在 str[i]~end范围查找
			string s = str.substr(i, pos - i);
			token.push_back(s);
			i = pos; //for循环会每次++
		}
		string re;
		for (int i = token.size() - 1; i > 0; i--) {
			re += token[i];
			re += " ";
		}
		re += token[0];
		return re;
	}
};

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define D(x) cout<<#x<<"="<<x<<endl;
int main(int argc, char *argv[]) {
	string str = "I am a student.";
	str += " ";
	vector<string> token;
	int len = str.size();
	for (int i = 0; i < len; ++i)
	{
		int pos = str.find(" ", i); //在 str[i]~end范围查找
		string s = str.substr(i, pos - i);
		token.push_back(s);
		i = pos; //for循环会每次++
	}
	string x;
	for (int i = token.size() - 1; i > 0; i--) {
		x += token[i];
		x += " ";
	}
	x += token[0];
	D(x)
	return 0;
}

题目应该有一个隐含条件，就是不能用额外的空间……
那就一次旋转整个字符串，一次旋转每个单词

class Solution {
public:
	string ReverseSentence(string str) {
		reverse(str.begin(), str.end());
		int i = 0, j = 0;
		while (j <= str.size()) {
			if (str[j] == ' ' || j == str.size()) { //这样避免了在str后加空格的尴尬
				reverse(str.begin() + i, str.begin() + j);
				i = j + 1;
			}
			j++;
		}
		return str;
	}
};

