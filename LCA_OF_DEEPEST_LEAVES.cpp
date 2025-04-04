#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};
class Solution
{
public:
    unordered_map<int, int> m;
    int maxd = 0;
    TreeNode *lca(TreeNode *root)
    {
        if (!root || m[root->val] == maxd)
            return root;
        TreeNode *left = lca(root->left);
        TreeNode *right = lca(root->right);
        if (right && left)
        {
            return root;
        }
        if (!right && left)
        {
            return left;
        }
        if (right && !left)
        {
            return right;
        }
        return NULL;
    }

    void depth(TreeNode *root, int d)
    {
        if (!root)
            return;
        maxd = max(d, maxd);
        m[root->val] = d;
        depth(root->left, d + 1);
        depth(root->right, d + 1);
    }

    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        depth(root, 0);
        return lca(root);
    }
};