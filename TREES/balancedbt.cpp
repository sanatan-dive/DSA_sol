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
    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root) != -1;
    }

private:
    int isBalancedHelper(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh = isBalancedHelper(root->left);
        if (lh == -1) return -1;  // If left subtree is unbalanced, return -1

        int rh = isBalancedHelper(root->right);
        if (rh == -1) return -1;  // If right subtree is unbalanced, return -1

        if (abs(lh - rh) > 1) return -1;  // If the difference in heights is > 1, return -1 (unbalanced)

        return max(lh, rh) + 1;  // Return height of the subtree
    }
};
