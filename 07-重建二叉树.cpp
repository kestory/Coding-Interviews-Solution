class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
		int len = pre.size();
		if (len == 0)
			return NULL;
		// 前序遍历的第一个结点是根节点
		TreeNode* root = new TreeNode(pre[0]);
		// 在中序遍历中查找到根的位置，使用find
		vector<int>::iterator it = find(in.begin(), in.end(), pre[0]);
		int rootIndex = it-in.begin();
		// for (rootIndex = 0; rootIndex < len; rootIndex++)
		// 	if (in[rootIndex] == pre[0])
		// 		break;
		vector<int> preLeft, preRight, inLeft, inRight;
		for (int i = 0; i < rootIndex; ++i)
		{
			preLeft.push_back(pre[i + 1]); //前序第一个为根节点
			inLeft.push_back(in[i]);
		}
		for (int i = rootIndex + 1; i < len; ++i)
		{
			preRight.push_back(pre[i]);
			inRight.push_back(in[i]);
		}
		root->left = reConstructBinaryTree(preLeft, inLeft);
		root->right = reConstructBinaryTree(preRight, inRight);
		return root;
	}
};


class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
		TreeNode *root = reConstructBinaryTree(pre, 0, pre.size() - 1, in, 0, in.size() - 1);
		return root;
	}
	TreeNode* reConstructBinaryTree(vector<int> pre, int startPre, int endPre, vector<int> in, int startIn, int endIn) {
		if ((startPre > endPre) || (startIn > endIn))
			return NULL;
		TreeNode *root = new TreeNode(pre[startPre]);
		int i;//查找到的根的位置
		for (i = startIn; i <= endIn; i++)
			if (in[i] == pre[startPre])
				break;
		root->left = reConstructBinaryTree(pre, startPre + 1, startPre + i - startIn, in, startIn, i - 1);
		root->right = reConstructBinaryTree(pre, i - startIn + startPre + 1, endPre, in, i + 1, endIn);
		return root;
	}
};
