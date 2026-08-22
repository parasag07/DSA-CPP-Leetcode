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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* newnode = new TreeNode(val);
            root = newnode;
            return root;
        }
        if(!root->left && !root->right){
            TreeNode* newnode = new TreeNode(val);
            if(val > root->val) root->right = newnode;
            else root->left = newnode;

            return root;
        }

        if(val > root->val){
            if(root->right)
                insertIntoBST(root->right, val);
            else {
                TreeNode* newnode = new TreeNode(val);
                root->right = newnode;
                return root;
            }
        } 
        if(val < root->val){
            if(root->left)
                insertIntoBST(root->left, val);
            else {
                TreeNode* newnode = new TreeNode(val);
                root->left = newnode;
                return root;
            }
        } 

        return root;
    }
};