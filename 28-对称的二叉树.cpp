class Solution {
public:
	bool isSymmetrical(TreeNode* l1, TreeNode* l2)
	{
		if (l1 == NULL && l2 == NULL)
			return true;
		if (l1 == NULL || l2 == NULL)
			return false;
		if (l1->val != l2->val)
			return false;
		return isSymmetrical(l1->left, l2->right) && isSymmetrical(l1->right, l2->left);

	}
	bool isSymmetrical(TreeNode* pRoot)
	{
		return isSymmetrical(pRoot, pRoot);
	}
};
