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
    // is balanced , height
    int isTreebalanced(TreeNode* root, bool &balanced){
        if(root==nullptr){
            return 0;
        }

        int left = isTreebalanced(root->left, balanced);
        int right = isTreebalanced(root->right, balanced);

        if(abs(left-right) > 1){
            balanced = false;
           // break;
        }
        return max(left, right)+1;
        

    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        bool balanced = true;
        isTreebalanced(root, balanced);
        return balanced;
    }
};
