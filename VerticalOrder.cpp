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
        map<int,map<int,vector<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;
        vector<vector<int>>all_ans;
        if(root==NULL)
        {
            return all_ans;
        }
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty())
        {
            pair<TreeNode*,pair<int,int>>temp=q.front();
            TreeNode* frontnode=temp.first;
            int hd=temp.second.first;
            int ld=temp.second.second;
            q.pop();
            nodes[hd][ld].push_back(frontnode->val);
            if(frontnode->left)
            {
                q.push(make_pair(frontnode->left,make_pair(hd-1,ld+1)));
            }
            if(frontnode->right)
            {
                 q.push(make_pair(frontnode->right,make_pair(hd+1,ld+1)));
            }

        }
        vector<int>combinations;
        for (auto i : nodes) {
            vector<int> ans;
            for (auto j : i.second) {
                vector<int> values = j.second;
                sort(values.begin(), values.end());
                ans.insert(ans.end(), values.begin(), values.end());
            }
           all_ans.push_back(ans);
        }
        return all_ans;
    }
};
