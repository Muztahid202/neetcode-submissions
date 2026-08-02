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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       if(!root) return "";
        string encoded = "";
        //level order traversal(bfs)
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(!node) encoded.append("#,");
            else{
                encoded.append(to_string(node->val) + ",");
                q.push(node->left);
                q.push(node->right);
            }  
        } 
        return encoded; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

        stringstream ss(data);
        queue<TreeNode*> q;
        string val;
        getline(ss, val, ',');
        //creating the root node
        TreeNode* root = new TreeNode(stoi(val));
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(ss, val, ',');
            if(val == "#") node->left = NULL;
            else{
                TreeNode* left = new TreeNode(stoi(val));
                node->left = left;
                q.push(left);
            }

            getline(ss, val, ',');
            if(val == "#") node->right = NULL;
            else{
                TreeNode* right = new TreeNode(stoi(val));
                node->right = right;
                q.push(right);
            }

        }
        return root;
    }
};

//TC = O(N)
//Sc = O(N)
