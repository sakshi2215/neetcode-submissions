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
    // height, diameter
    pair<int, int> getDiameter(TreeNode* root){
        if(root == nullptr) {
            return {0, 0};
        }

        pair<int, int>left = getDiameter(root->left);
        pair<int, int>right = getDiameter(root->right);

        int maxHeight = max(left.first, right.first);
        int maxDiameter = max(left.second, max(right.second, left.first + right.first));
        return {maxHeight+1, maxDiameter};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return getDiameter(root).second;
    }
};
