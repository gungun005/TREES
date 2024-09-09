
void level_traversal(Node *root,vector<int>&rightview)
{
    queue<Node*>q;
    q.push(root);
    vector<int>traversal;
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            traversal.push_back(q.front()->data);
            if(q.front()->left)
            {
                q.push(q.front()->left);
            }
            if(q.front()->right)
            {
                q.push(q.front()->right);
            }
            
            q.pop();
        }
        reverse(traversal.begin(),traversal.end());
        rightview.push_back(traversal[0]);
        traversal.erase(traversal.begin(),traversal.end());
        
    }
}
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int>rightview;
        level_traversal(root,rightview);
        return rightview;
       // Your Code here
    }
