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
private:
    TreeNode* findMin(TreeNode* root) {
        while(root->left)
            root = root->left;

        return root;
    }

    TreeNode* deleteNodeHelper(TreeNode* root, int key) {
        if(!root)
            return nullptr;

        if(key < root->val) {
            root->left = deleteNodeHelper(root->left, key);
        }
        else if(key > root->val) {
            root->right = deleteNodeHelper(root->right, key);
        }
        else {
            if(!root->left)
                return root->right;

            if(!root->right)
                return root->left;

            TreeNode* successor = findMin(root->right);

            root->val = successor->val;

            root->right = deleteNodeHelper(root->right, successor->val);
        }

        return root;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteNodeHelper(root, key);
    }
};