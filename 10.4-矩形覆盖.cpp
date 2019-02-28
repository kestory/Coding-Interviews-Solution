/*
f(8)=f(7)+f(6)
f(1)=1
f(2)=2//其实按中心对称还是1
*/
class Solution {
public:
  int rectCover(int number) {
    if (number <= 2)
      return number;
    int one = 1, two = 2;
    int res = 0;
    for (int i = 3; i <= number; i++) {
      res = one + two;
      one = two;
      two = res;
    }
    return res;

  }
};
