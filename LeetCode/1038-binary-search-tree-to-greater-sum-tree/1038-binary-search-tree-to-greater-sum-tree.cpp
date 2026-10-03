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

    void fill_node(TreeNode* node, int& cur_sum)
    {
        if(node->left)
            fill_node(node->left, cur_sum);

            cur_sum -= node->val;
            node->val += cur_sum;

        if(node->right)
            fill_node(node->right, cur_sum);
    }
    int get_sum(TreeNode* node)
    {
        int sum = node->val;
        if(node->left)
            sum += get_sum(node->left);
        
        if(node->right)
            sum += get_sum(node->right);

        return sum;
    }
    TreeNode* bstToGst(TreeNode* root) {

        int sum = get_sum(root);

// cout << "sum : "<< sum << "\n";
        fill_node(root, sum);

        return root;
    }
};