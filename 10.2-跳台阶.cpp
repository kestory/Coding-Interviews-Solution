class Solution {
public:
  int jumpFloor(int n) {
    int a[n];
    a[1] = 1;
    a[2] = 2;
    for (int i = 3; i <= n; ++i)
      a[i] = a[i - 1] + a[i - 2];

    return a[n];
  }
};

class Solution {
public:
  int jumpFloor(int number) {
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
