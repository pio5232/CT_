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
        
    int nodes_depth[102];
    int parent[102];

    void go(TreeNode* node, int parent_value, int depth)
    {
        const int node_value = node->val;
        nodes_depth[node_value] = depth;
        parent[node_value] = parent_value;
        
        if(node->left)
            go(node->left, node_value, depth+1);
        
        if(node->right)
            go(node->right, node_value, depth+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {

        fill_n(parent, 102, -1);
        fill_n(nodes_depth, 102, -1);
        
        go(root, -1,0);

        return nodes_depth[x] == nodes_depth[y] && parent[x] != parent[y];
    }
};