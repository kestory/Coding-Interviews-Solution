#include <iostream>
using namespace std;
#define D(x) cout<<#x<<"="<<x<<endl;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
};
// 右子树不为空，下一个节点是右子树的最左节点；
// 无右子树，向上找到第一个是其父节点的左子节点的节点，即当前结点所在的左子树的根
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        TreeLinkNode* pNext = NULL;
        if (pNode->right != NULL) {
            pNext = pNode->right;
            while (pNext->left != NULL) {
                pNext = pNext->left;
            }
            return pNext;
        }
        else {
            TreeLinkNode* Current = pNode;
            TreeLinkNode* Parent = pNode->next;
            while (Parent != NULL) {
                if (Current == Parent->left)//就是这里不能用val来比较：(Current->val == Parent->left->val)，会段错误！
                    return Parent;//所以就比较地址就行，节点都在树中
                Current = Parent;
                Parent = Parent->next;
            }
        }
        return NULL;
    }
};

void InOrder(TreeLinkNode *tree) {
    if (tree == NULL)
    {
        return;
    }
    InOrder(tree->left);
    cout << tree->val;
    InOrder(tree->right);
}

int main( )
{
    Solution solu;
    TreeLinkNode tree[10];

    tree[0].val = 4;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];
    tree[0].next = NULL;

    tree[1].val = 2;
    tree[1].left = &tree[3];
    tree[1].right = &tree[4];
    tree[1].next = &tree[0];

    tree[2].val = 5;
    tree[2].left = NULL;
    tree[2].right = &tree[5];
    tree[2].next = &tree[0];

    tree[3].val = 1;
    tree[3].left = &tree[6];
    tree[3].right = NULL;
    tree[3].next = &tree[1];

    tree[4].val = 3;
    tree[4].left = NULL;
    tree[4].right = NULL;
    tree[4].next = &tree[1];

    tree[5].val = 9;
    tree[5].left = &tree[7];
    tree[5].right = NULL;
    tree[5].next = &tree[2];

    tree[6].val = 0;
    tree[6].left = NULL;
    tree[6].right = NULL;
    tree[6].next = &tree[3];

    tree[7].val = 7;
    tree[7].left = &tree[8];
    tree[7].right = &tree[9];
    tree[7].next = &tree[5];

    tree[8].val = 6;
    tree[8].left = NULL;
    tree[8].right = NULL;
    tree[8].next = &tree[7];

    tree[9].val = 8;
    tree[9].left = NULL;
    tree[9].right = NULL;
    tree[9].next = &tree[7];

    InOrder(tree);
    cout << endl;

    cout << solu.GetNext(&tree[6])->val << endl;
    cout << solu.GetNext(&tree[3])->val << endl;
    cout << solu.GetNext(&tree[1])->val << endl;
    cout << solu.GetNext(&tree[4])->val << endl;
    cout << solu.GetNext(&tree[0])->val << endl;
    cout << solu.GetNext(&tree[2])->val << endl;
    cout << solu.GetNext(&tree[8])->val << endl;
    cout << solu.GetNext(&tree[7])->val << endl;
    cout << solu.GetNext(&tree[9])->val << endl;
    // cout << solu.GetNext(&tree[5])->val << endl;//段错误
    return 0;
}
