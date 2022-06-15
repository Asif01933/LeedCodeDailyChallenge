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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*, pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            TreeNode* node=x.first;
            int vert=x.second.first, level=x.second.second;
            mp[vert][level].insert(node->val);
            if(node->left) q.push({node->left, {vert-1,level+1}});
            if(node->right) q.push({node->right, {vert+1,level+1}});
        }
        vector<vector<int>>ans;
        for(auto v:mp){
            vector<int>col;
            for(auto u:v.second){
                col.insert(col.end(),u.second.begin(),u.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};