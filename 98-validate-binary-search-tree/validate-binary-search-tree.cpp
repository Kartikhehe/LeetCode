class Solution {
public:
    // Added default minNode and maxNode parameters
    bool isValidBST(TreeNode* root, TreeNode* minNode = nullptr, TreeNode* maxNode = nullptr) {
        if(root == nullptr) return true;
        
        // Replaced immediate child checks with checks against the ancestor limits
        if(minNode && root->val <= minNode->val) return false;
        if(maxNode && root->val >= maxNode->val) return false;
        
        // Passed the current root down as the new limit for the subtrees
        bool left = isValidBST(root->left, minNode, root);
        bool right = isValidBST(root->right, root, maxNode);
        
        if(!left || !right) return false;
        return true;
    }
};