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
    void find(TreeNode* root, TreeNode* x, vector<TreeNode*>& lca){
        if(!root) return;
        if(root == x){
            lca.push_back(root);
            return;
        }

        lca.push_back(root);
        
        if(root->val > x->val) find(root->left, x,lca);
        else find(root->right, x, lca);

    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pv;
        vector<TreeNode*> qv;

        find(root, p, pv);
        find(root, q, qv);

        TreeNode* lca = root;
        int i = 0;
        int j = 0;

        while(i < pv.size() && j < qv.size()){
            if(pv[i] == qv[j]){
                lca = pv[i];
                i++;
                j++;
            }
            else break;
        }

        return lca;
    }
};