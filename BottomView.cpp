vector <int> bottomView(Node *root) {
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
            topnode[hd]=frontnode->data;
            
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
