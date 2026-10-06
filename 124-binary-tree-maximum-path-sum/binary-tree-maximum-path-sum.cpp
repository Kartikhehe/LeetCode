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
    int helper(TreeNode* root, int &maxH){
        if(!root)return 0;
        int left = helper(root->left, maxH);
        int right = helper(root-> right, maxH);
        maxH = max(maxH, root->val + (left > 0 ? left : 0) + (right > 0 ? right : 0));
        return root->val + max(0,(max(left, right)));
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxH = INT_MIN;
        helper(root, maxH);
        return maxH == INT_MIN ? 0: maxH;
    }
};