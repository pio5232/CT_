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
    int findBottomLeftValue(TreeNode* root) {

        queue<pair<TreeNode*, int>> q;
        int depth = -1;
        
        q.push({root, 0});
        int ans = 0;

        while(q.size())
        {
            auto [node, cur_depth] = q.front();
            q.pop();

            if(cur_depth > depth)
            {
                depth = cur_depth;
                ans = node->val;
            }

            if(node->left)
                q.push({node->left, cur_depth+1});
            
            if(node->right)
                q.push({node->right, cur_depth+1});
        }
        
        return ans;
    }
};