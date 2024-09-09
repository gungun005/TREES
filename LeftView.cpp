void level_traversal(Node *root,vector<int>&left_view)
{
    vector<int>traversal;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int x=q.size();
        for(int i=0;i<x;i++)
        {
            traversal.push_back(q.front()->data);
            if(q.front()->left)
            {
                 q.push(q.front()->left);
                // traversal.push_back(q.front()->left->data);
            }
            if(q.front()->right)
            {
                q.push(q.front()->right);
                // traversal.push_back(q.front()->right->data);
            }
            q.pop();
        }
        left_view.push_back(traversal[0]);
        traversal.erase(traversal.begin(),traversal.end());
    }
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int>left_view;
    level_traversal(root,left_view);
    return left_view;
   // Your code here
}
