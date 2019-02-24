#include <iostream>
#include <vector>
#define D(x) cout<<#x<<"="<<x<<endl;
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {

        int row = array.size();
        int col = array[0].size();
        int r = 0;
        int c = col - 1;
//      int x = array[r][c]; //从右上角开始
        while (c >= 0 && r < row) {
//          D(r)D(c)
            if (target < array[r][c])
                c--;
            else if (target > array[r][c])
                r++;
            else
                return true;
        }
        return false;
    }
};

int main()
{
    int a1[] = { 1, 2, 8, 9, };
    int a2[] = { 2, 4, 9, 12, };
    int a3[] = { 4, 7, 10, 13, };
    int a4[] = { 6, 8, 11, 15, };
    vector<vector<int> > array;
    array.push_back(vector<int>(a1, a1 + 4));
    array.push_back(vector<int>(a2, a2 + 4));
    array.push_back(vector<int>(a3, a3 + 4));
    array.push_back(vector<int>(a4, a4 + 4));

    Solution solu;
    cout << solu.Find(7, array) << endl;
    return 0;
}








class Solution {//从左下角开始
public:
    bool Find(int target, vector<vector<int> > array) {

        int row = array.size();
        int col = array[0].size();
        int r = row - 1;
        int c = 0;
        while (r >= 0 && c < col) {
            if (target < array[r][c])
                r--;
            else if (target > array[r][c])
                c++;
            else
                return true;
        }
        return false;
    }
};
