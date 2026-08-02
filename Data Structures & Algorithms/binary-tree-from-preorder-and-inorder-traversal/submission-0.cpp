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
    TreeNode* buildTreeHelper(unordered_map<int, int> &indexMapping, int preBegin, int preEnd, int inBegin, int inEnd, vector<int>& preorder, vector<int>& inorder){
        if(preBegin > preEnd || inBegin > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preBegin]);

        int rootIndex = indexMapping[root->val]; //finding the index of the root in inorder
        int numLeft = rootIndex - inBegin;

        root->left = buildTreeHelper(indexMapping, preBegin + 1, preBegin + numLeft, inBegin, rootIndex-1, preorder, inorder);

        root->right = buildTreeHelper(indexMapping, preBegin + numLeft + 1, preEnd, rootIndex + 1, inEnd, preorder, inorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //hashing the elements of inorder traversal
        unordered_map<int, int> indexMapping;
        for(int i = 0; i < inorder.size(); i++){
            indexMapping[inorder[i]] = i;
        }

        TreeNode* root = buildTreeHelper(indexMapping, 0, preorder.size()-1, 0, inorder.size()-1, preorder, inorder);

        return root;
    }
};

//TC = O(N)
//SC = O(N)

