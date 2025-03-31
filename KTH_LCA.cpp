/**
 * Definition for a binary tree node.
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution

{
public:
    void solve(TreeNode *root, vector<TreeNode *> &vec, TreeNode *p, bool &f)
    {
        if (!root)
            return;
        if (f)
            return;
        vec.push_back(root);
        // cout << "for r = " << root->val << endl;
        // for (auto& i : vec)
        //     cout << i->val << " ";
        // cout << endl;
        if (root == p)
        {
            f = true;
            return;
        }
        solve(root->left, vec, p, f);
        if (f)
            return;
        solve(root->right, vec, p, f);
        if (f)
            return;
        vec.pop_back();
        return;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> pp, qq;
        bool f = false;
        bool g = false;
        solve(root, pp, p, f);
        cout << "qqQQqq" << endl;
        solve(root, qq, q, g);
        int m = pp.size();
        int n = qq.size();
        for (auto &i : pp)
            cout << i->val << " ";
        cout << endl;
        for (auto &i : qq)
            cout << i->val << " ";
        cout << endl;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (pp[i] == qq[j])
                {
                    return pp[i];
                }
            }
        }
        return root;
    }
};