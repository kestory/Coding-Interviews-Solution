#栈的方法：先把l1和l2分别入栈，通过栈顶是否相等判断是否相交。如果相交的话，则同时出栈，直到遇到出栈的节点不同，那前一个节点便是相交的入口
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
#define D(x) cout<<#x<<"="<<x<<endl;

struct ListNode {
	int val;
	struct ListNode *next;
};

class Solution {
public:
	ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
		stack<ListNode*>l1;
		stack<ListNode*>l2;
		//依次入栈
		while (pHead1 != NULL) {
			l1.push(pHead1);
			pHead1 = pHead1->next;
		}
		while (pHead2 != NULL) {
			l2.push(pHead2);
			pHead2 = pHead2->next;
		}

//		for (; !l1.empty(); l1.pop())
//				cout << l1.top()->val << " ";
//		cout<<endl;
//        for (; !l2.empty(); l2.pop())
//            cout << l2.top()->val << " ";

		ListNode* t1;
		ListNode* t2;
		while (!l1.empty() && !l2.empty()) {
			t1 = l1.top();
			t2 = l2.top();
//            D(t->val)
			if (t1 != t2) //if(l1.top()!=l2.top())这样写在oj会崩
				break;
			l1.pop();
			l2.pop();
		}
		if (t1 != t2)
			return t1->next;
		else
			return NULL;

	}
};

int main( )
{
	ListNode common[2];
	common[0].val = 6;
	common[0].next = &common[1];
	common[1].val = 7;
	common[1].next = NULL;

	ListNode left[3];
	left[0].val = 1;
	left[0].next = &left[1];
	left[1].val = 2;
	left[1].next = &left[2];
	left[2].val = 3;
	left[2].next = &common[0];

	ListNode right[2];
	right[0].val = 4;
	right[0].next = &right[1];
	right[1].val = 5;
	right[1].next = &common[0];

//    7 6  3 2 1
//    7 6  5 4

	Solution solu;
	ListNode *node = solu.FindFirstCommonNode(left, right);
	while (node != NULL)
	{
		cout << node->val << " ";
		node = node->next;
	}
	return 0;
}

#Hash法
class Solution {
public:
	ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
		unordered_map<ListNode*, int> m;
		for (; pHead1 != NULL; pHead1 = pHead1->next)
			m.insert(pair<ListNode*, int>(pHead1, 1));

		unordered_map<ListNode*, int>::iterator it;
		for (; pHead2 != NULL; pHead2 = pHead2->next)
			for (it = m.begin(); it != m.end(); it++)
				if (m.find(pHead2) != m.end())
					return pHead2;

		return NULL;//OJ的需要
	}
};


#暴力 O(n^2)
class Solution {
public:
	ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
		vector<ListNode*> v;
		for (; pHead1 != NULL; pHead1 = pHead1->next)
			v.push_back(pHead1);

		for (; pHead2 != NULL; pHead2 = pHead2->next)
			for (int i = 0; i < v.size(); ++i)
				if (v[i] == pHead2)
					return v[i];

		return NULL;
	}
};


#CS-Notes法
设 A 的长度为 a + c，B 的长度为 b + c，其中 c 为尾部公共部分长度，可知 a + c + b = b + c + a。
当访问链表 A 的指针访问到链表尾部时，令它从链表 B 的头部重新开始访问链表 B；
同样地，当访问链表 B 的指针访问到链表尾部时，令它从链表 A 的头部重新开始访问链表 A。
这样就能控制访问 A 和 B 两个链表的指针能同时访问到交点。


class Solution {
public:
	ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
		ListNode* l1 = pHead1;
		ListNode* l2 = pHead2;
		while (l1 != l2) {
			l1 = (l1 == null) ? pHead2 : l1->next;
			l2 = (l2 == null) ? pHead1 : l2->next;
		}
		return l1;
	}
};
