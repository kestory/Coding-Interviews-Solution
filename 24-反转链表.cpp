/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

三指针滑动pPrev -> pNode -> pNext;
pNode->next = pPrev;
pPrev = pNode;
pNode = pNext;

*/
#include <iostream>
#define D(x) cout<<#x<<"="<<x<<endl;
using namespace std;

struct ListNode
{
public :
	int val;
	struct ListNode *next;

};
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL)
			return NULL;
		if (pHead->next == NULL)
			return pHead;

//		ListNode *pNode = pHead->next;
//		ListNode *pPrev = pHead;
		ListNode *pNode = pHead;
		ListNode *pPrev = NULL;

		while (pNode != NULL) {
//			D(pNode->val)
			ListNode *pNext = pNode->next;
			pNode->next = pPrev;
			pPrev = pNode;
			pNode = pNext;
		}
		return pPrev;
	}
};

int main( )
{
	ListNode list[5];
	list[0].val = 1;
	list[0].next = &list[1];
	list[1].val = 2;
	list[1].next = &list[2];
	list[2].val = 3;
	list[2].next = &list[3];
	list[3].val = 4;
	list[3].next = &list[4];
	list[4].val = 5;
	list[4].next = NULL;


	ListNode *node = list;
	while (node != NULL)
	{
		cout << node->val;
		node = node->next;
	}
	cout << endl;


	Solution solu;
	node = solu.ReverseList(list);
	while (node != NULL)
	{
		cout << node->val;
		node = node->next;
	}
	cout << endl;

	return 0;

}



