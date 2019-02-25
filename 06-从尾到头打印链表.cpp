/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*  vector是用来返回的
*/

//使用栈来保存
class Solution {
public:
  vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> res;
    stack<int> st;
    ListNode* node = head;
    while (node != NULL) {
      st.push(node->val);
      node = node->next;
    }
    while (!st.empty()) {
      res.push_back(st.top());
      st.pop();
    }

    return res;

  }
};

//预先计数，静态分配vector空间//两个循环换成for
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
struct ListNode
{
public :
  int val;
  struct ListNode *next;
};
class Solution {
public:
  vector<int> printListFromTailToHead(ListNode* head) {

    stack<int> st;
    int count = 0;
    ListNode* node = head;
    // while(node!=NULL){
    for (; node != NULL; ++count) {
      st.push(node->val);
      node = node->next;
    }
    vector<int> res(count);
    for (int i = 0; i < count && st.empty() != true; ++i) {
      // while(!st.empty()){
      res[i] = st.top();
      st.pop();
    }

    return res;

  }
};
int main( )
{
  ListNode list[4];
  list[0].val = 1;
  list[0].next = &list[1];
  list[1].val = 2;
  list[1].next = &list[2];
  list[2].val = 3;
  list[2].next = &list[3];
  list[3].val = 4;
  list[3].next = NULL;

  Solution solu;
  vector<int> res = solu.printListFromTailToHead(list);

  for (int i = 0; i < res.size( ); i++)
    cout << res[i] << '\t';
  return 0;
}

//递归本质就是栈结构，自然联想到递归实现
class Solution {
public:
  vector<int> res;

  vector<int> printListFromTailToHead(ListNode* head) {
    if (head != NULL) {
      printListFromTailToHead(head->next);
      res.push_back(head->val);
    }
    return res;
  }

};
