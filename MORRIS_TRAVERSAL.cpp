#include <bits/stdc++.h>
using namespace std;
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> ans;
        TreeNode *curr = root;
        while (curr)
        {
            TreeNode *left = curr->left;
            if (!left)
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *predeccessor = curr->left;
                while (predeccessor->right && predeccessor->right != curr)
                {
                    predeccessor = predeccessor->right;
                }
                if (!predeccessor->right)
                {
                    predeccessor->right = curr;
                    curr = curr->left;
                }
                else
                {
                    predeccessor->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};