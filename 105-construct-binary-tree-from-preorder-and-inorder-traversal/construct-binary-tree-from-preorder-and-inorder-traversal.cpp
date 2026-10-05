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
    TreeNode* builder(vector<int>& preorder, vector<int>& inorder , int px, int py, int ix, int iy){
        if(px > py || ix > iy)return nullptr;
        int root = preorder[px];
        int lefttreesize = find(inorder.begin(), inorder.end(), root) - inorder.begin() - ix;
        TreeNode* lefttree = builder(preorder, inorder, px+1,px + lefttreesize, ix, ix + lefttreesize-1 );
        TreeNode* righttree = builder(preorder, inorder, px + lefttreesize + 1, py, ix + lefttreesize + 1, iy);

        TreeNode* answernode = new TreeNode(root);
        answernode->left = lefttree;
        answernode->right = righttree;
        return answernode;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //get root from preorder first
        //find the root and you get the left all variables 
        //maybe use recursion??
        return builder(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);

    }
};