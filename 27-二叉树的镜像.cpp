class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == NULL)
			return;

		// swap(pRoot->left, pRoot->right);
		TreeNode* t = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = t;

		Mirror(pRoot->left);
		Mirror(pRoot->right);

	}
};
