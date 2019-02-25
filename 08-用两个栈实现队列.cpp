//一管液体先倒入水杯1，再经过水杯2倒出，要水时，水杯2有水就倒出，无水就把水杯1的倒入，都没有就无水。
class Solution
{
public:
  void push(int node) {
    stack1.push(node);
  }

  int pop() {
    if (stack2.empty()) {
      while (!stack1.empty()) {
        int t = stack1.top();
        stack2.push(t);
        stack1.pop();
      }
    }

    int node = stack2.top();
    stack2.pop();
    return node;

  }

private:
  stack<int> stack1;
  stack<int> stack2;
};
