#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
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
    int findPos(vector<int> in, int ele, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (in[i] == ele)
                return i;
        }
        return -1;
    }

    TreeNode *solve(vector<int> in, vector<int> pre, int &index, int is, int ie,
                    int n)
    {
        if (index >= n || is > ie)
            return NULL;
        int ele = pre[index++];
        TreeNode *root = new TreeNode(ele);
        int pos = findPos(in, ele, n);
        root->left = solve(in, pre, index, is, pos - 1, n);
        root->right = solve(in, pre, index, pos + 1, ie, n);
        return root;
    }

    TreeNode *buildTree(vector<int> &pre, vector<int> &in)
    {
        int n = in.size(), index = 0;
        TreeNode *ans = solve(in, pre, index, 0, n - 1, n);
        return ans;
    }
};