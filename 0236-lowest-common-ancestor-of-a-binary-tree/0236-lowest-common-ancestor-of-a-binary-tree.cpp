/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private: 
    void preorderFind(vector<TreeNode*>& vec, TreeNode* root, TreeNode* k){
        if(!root) return;
        if(root == k){
            vec.push_back(root);
            return;
        }

        vec.push_back(root);
        preorderFind(vec, root->left, k);
        preorderFind(vec, root->right, k);
        if(vec.back() != k) vec.pop_back();
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vecp;
        vector<TreeNode*> vecq;

        preorderFind(vecp, root, p);
        preorderFind(vecq, root, q);

        for(int i = vecp.size()-1; i >= 0; i--){
            for(int j = vecq.size()-1; j >= 0; j--){
                if(vecp[i] == vecq[j]) return vecp[i];
            }
        }

        return nullptr;
    }
};