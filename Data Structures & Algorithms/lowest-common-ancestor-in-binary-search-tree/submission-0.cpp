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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        int curr = root->val;
        //if p and q is greater than the root value then search in the right subtree
        if(curr < p->val && curr < q->val) return lowestCommonAncestor(root->right, p, q);
        //if p and q is smaller than the root value then search in the left subtree
        if(curr > p->val && curr > q->val) return lowestCommonAncestor(root->left, p, q);
        return root; //this is the node where path splitted
    }
};


//TC = O(Height of the tree)
//SC = O(1) though stack space is tehre for recursion so more memory will get consumed
