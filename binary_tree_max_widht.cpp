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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)return 0;
        queue<pair<TreeNode*, unsigned long long int>> que;
        que.push({root, 0});
        int width = 0;
        while (que.size() != 0) {
            unsigned long long int left = que.front().second, right = 0;
            int n = que.size();
            for(int i=0;i<n;i++){
                pair<TreeNode*, unsigned long long int> rNode = que.front();
                que.pop();
                right = rNode.second;
                if (rNode.first->left) {
                    que.push({rNode.first->left, 2 * rNode.second + 1});
                }
                if (rNode.first->right) {
                    que.push({rNode.first->right, 2 * rNode.second + 2});
                }
            }
            width = max(width, int(right - left + 1));
        }
        return width;
    }
};