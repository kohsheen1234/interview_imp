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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int levelSize = q.size();  // Fix here: Capture the size of the queue representing the current level.

            for (int i = 0; i < levelSize; ++i) {  // Use the captured size for loop iteration
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                
                if (node->left) {
                    q.push(node->left);  // Add child nodes to the queue for the next level
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            ans.push_back(level);  // Add the current level's results to the answer list
        }
        return ans;
    }
};
