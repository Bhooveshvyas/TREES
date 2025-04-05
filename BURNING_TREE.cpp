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
}; /**
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
class Solution
{
public:
    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<TreeNode *, TreeNode *> m;
        deque<TreeNode *> dq;
        dq.push_back(root);
        m[root] = NULL;
        TreeNode *targetNode = NULL;
        while (!dq.empty())
        {
            TreeNode *curr = dq.front();
            if (curr->val == start)
                targetNode = curr;
            dq.pop_front();
            if (curr->left)
            {
                m[curr->left] = curr;
                dq.push_back(curr->left);
            }
            if (curr->right)
            {
                m[curr->right] = curr;
                dq.push_back(curr->right);
            }
        }

        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(targetNode);
        int time = 0;
        visited[targetNode] = true;

        while (!q.empty())
        {
            int sz = q.size();
            bool insertion = false;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                TreeNode *left = curr->left;
                if (left && !visited[left])
                {
                    q.push(left);
                    visited[left] = true;
                    insertion = true;
                }
                TreeNode *right = curr->right;
                if (right && !visited[right])
                {
                    q.push(right);
                    visited[right] = true;
                    insertion = true;
                }
                TreeNode *parent = m[curr];
                if (parent && !visited[parent])
                {
                    q.push(parent);
                    visited[parent] = true;
                    insertion = true;
                }
            }
            if (insertion == true)
                time++;
        }
        return time;
    }
};