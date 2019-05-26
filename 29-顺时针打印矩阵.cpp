#include <iostream>
#include <vector>
using namespace std;
#define D(x) cout<<#x<<"="<<x<<endl;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		int r1 = 0, r2 = matrix.size() - 1, c1 = 0, c2 = matrix[0].size() - 1;
		vector<int> v;
//		D(r1)D(r2)D(c1)D(c2)
		while (r1 <= r2 && c1 <= c2) {

			for (int i = c1; i <= c2; ++i)
				v.push_back(matrix[r1][i]);

//		if (r1 != r2)
			for (int i = r1 + 1; i <= r2; ++i)
				v.push_back(matrix[i][c2]);

//		if (c1 != c2)
			if (r1 != r2)
				for (int i = c2 - 1; i >= c1; --i)
					v.push_back(matrix[r2][i]);

//		if(r1!=r2)
			if (c1 != c2)
				for (int i = r2 - 1; i >= r1 + 1; --i)
					v.push_back(matrix[i][c1]);

			r1++; r2--; c1++; c2--;
		}
		return v;
	}
};


int main( )
{
	int a1[] = {  1,  2,  3,  4 };
	int a2[] = {  5,  6,  7,  8 };
	int a3[] = {  9, 10, 11, 12 };
	int a4[] = { 13, 14, 15, 16 };

	vector<int> vec1(a1, a1 + 4);
	vector<int> vec2(a2, a2 + 4);
	vector<int> vec3(a3, a3 + 4);
	vector<int> vec4(a4, a4 + 4);


	vector< vector<int> > vec;
	vec.push_back(vec1);
//	vec.push_back(vec2);
//	vec.push_back(vec3);
//	vec.push_back(vec4);

	Solution solu;
	vector<int> res = solu.printMatrix(vec);
	for (int i = 0; i < res.size( ); i++)
		cout << res[i] << " ";

	return 0;
}
