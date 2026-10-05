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
    void dfs(TreeNode* root, vector<TreeNode*> &sorted){
        if(!root) return;
        if(root->left){
            dfs(root->left, sorted);
        }
        sorted.push_back(root);
        if(root->right){
            dfs(root->right, sorted);
        }

        return;

    }


public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> sorted;
        TreeNode* temp = root;
        dfs(root, sorted);
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        for(int i = 0; i<sorted.size()-1; i++){
            if(sorted[i]->val > sorted[i+1]->val){
                if(first == nullptr){
                    first = sorted[i];
                    second = sorted[i+1];
                }else{
                    second = sorted[i+1];
                }
            }
        }

        int ok = first->val;
        first->val = second->val;
        second->val = ok;
        return;
    }
};