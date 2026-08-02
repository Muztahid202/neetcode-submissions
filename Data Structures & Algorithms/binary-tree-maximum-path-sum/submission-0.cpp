/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxPathSumHelper(TreeNode* root, int& maxPath){
        if(!root) return 0;

        int left = max(0, maxPathSumHelper(root->left, maxPath));
        int right = max(0, maxPathSumHelper(root->right, maxPath));

        maxPath = max(maxPath, left + right + root->val); //curvature path

        return root->val + max(left, right);

    }
    int maxPathSum(TreeNode* root) {
        int maxPath = root->val;
        maxPathSumHelper(root, maxPath);
        return maxPath;
    }
};
