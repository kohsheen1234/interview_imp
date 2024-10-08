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

    bool isSame(TreeNode* root, TreeNode* subRoot){
        if(root==subRoot) //both point to null pointer 
            return true;
        if(!root || !subRoot || root->val!= subRoot->val){
            return false;
        }

        return isSame(root->left, subRoot->left) && isSame(root->right,subRoot->right);

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;


       if((root->val == subRoot->val) && isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right)) 
            return true;
        //if s and t are not the same,
        //keep find t in s's subtree
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
    }
};

        
