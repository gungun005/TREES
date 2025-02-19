class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        map<int,int>topnode;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            pair<Node*,int>temp=q.front();
            q.pop();
            Node* frontnode=temp.first;
            int hd=temp.second;
            if(topnode.find(hd)==topnode.end())
            {
                topnode[hd]=frontnode->data;
            }
            if(frontnode->left)
            {
                q.push(make_pair(frontnode->left,hd-1));
            }
            if(frontnode->right)
            {
                q.push(make_pair(frontnode->right,hd+1));
            }
        }
        for(auto k:topnode)
        {
            ans.push_back(k.second);
        }
        return ans;
        
    }
};
