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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)return true;
        bool left = isValidBST(root->left);
        bool right = isValidBST(root->right);
        TreeNode* temp = root->left;
        while(temp!=nullptr && temp->right!=nullptr){
            temp = temp->right;
        }
        if(root->left && temp!=root && temp->val >= root->val)return false;
        temp = root->right;
        while(temp!=nullptr && temp->left!=nullptr){
            temp = temp->left;
        }
        if(root->right && temp!=root && temp->val <= root->val)return false;
        
        if(!left || !right)return false;
        return true;
    }
};