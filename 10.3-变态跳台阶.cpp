/*
1 ~ 1
2 ~ 2
3 ~ 1+2+1=4
4 ~ 1+2+4+1=8
f(n)=2^(n-1)
*/

class Solution {
public:
  int jumpFloorII(int number) {
    return pow(2, number - 1);
    //return 1 << (number - 1);
  }
};

class Solution {
public :
  int jumpFloorII(int target)
  {
    long long ret;
    if (target >= 32) {//大于8字节后，需要分两次移位，否则出错(……为啥呢)
      ret = 1 << 30;
      ret = ret << (target - 31);
    }
    else {
      ret = 1 << (target - 1);
    }
    return ret;
  }
};
