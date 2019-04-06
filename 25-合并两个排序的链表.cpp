//也是LeetCode 21
#include <iostream>
using namespace std;
#define D(x) cout<<#x<<"="<<x<<endl;
struct ListNode {
	int val;
	struct ListNode *next;
};
//递归版
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode *pResult = NULL;
		if (pHead1 == NULL)
			return pHead2;
		if (pHead2 == NULL)
			return pHead1;

		if (pHead1->val < pHead2->val) {
			// pResult = pHead1;
			pHead1->next = Merge(pHead1->next, pHead2);
			return pHead1;
		}
		else {
			// pResult = pHead2;
			pHead2->next = Merge(pHead1, pHead2->next);
			return pHead2;
		}
		// return pResult;
	}
};
int main( )
{
	ListNode left[3];
	ListNode right[3];

	left[0].val = 1;
	left[0].next = &left[1];
	left[1].val = 3;
	left[1].next = &left[2];
	left[2].val = 5;
	left[2].next = NULL;

	right[0].val = 2;
	right[0].next = &right[1];
	right[1].val = 4;
	right[1].next = &right[2];
	right[2].val = 6;
	right[2].next = NULL;


	Solution solu;
	ListNode *head = solu.Merge(left, right);
	while (head != NULL)
	{
		cout << head->val;
		head = head->next;
	}

	return 0;
}



//迭代版
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		//有空链表的情况
		if (pHead1 == NULL)
			return pHead2;
		if (pHead2 == NULL)
			return pHead1;
		//生成头结点
		ListNode *pHead = NULL;
		if (pHead1->val < pHead2->val) {
			pHead = pHead1;
			pHead1 = pHead1->next;
		}
		else {
			pHead = pHead2;
			pHead2 = pHead2->next;
		}
//			D(pHead->val)
		ListNode *pCurr = pHead;
		//遍历两个链表
		while (pHead1 != NULL && pHead2 != NULL) {
//				D(pCurr->val)
			if (pHead1->val < pHead2->val) {
				pCurr->next = pHead1;
				pHead1 = pHead1->next;
				pCurr = pCurr->next;
			}
			else {
				pCurr->next = pHead2;
				pHead2 = pHead2->next;
				pCurr = pCurr->next;
			}
		}

		//处理剩余部分
		if (pHead1 != NULL)
			pCurr->next = pHead1;
		if (pHead2 != NULL)
			pCurr->next = pHead2;

		return pHead;//返回这个！
	}
};
