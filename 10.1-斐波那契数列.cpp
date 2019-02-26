class Solution {//保存了一个数组
public:
  int Fibonacci(int n) {
    int a[n];
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= n; ++i)
      a[i] = a[i - 1] + a[i - 2];

    return a[n];
  }
};


class Solution {//毫无保留
public:
  int Fibonacci(int n) {
    if (n <= 1)
      return n;
    int one = 0, two = 1;
    int res = 0;
    for (int i = 2; i <= n; i++) {
      res = one + two;
      one = two;
      two = res;
    }
    return res;
  }
};

//由于待求解的 n 小于 40，因此可以将前 40 项的结果先进行计算
class Solution {
public:
  int a[41];
  Solution() {
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i < 41; i++)
      a[i] = a[i - 1] + a[i - 2];
  }
  int Fibonacci(int n) {
    return a[n];
  }
};
