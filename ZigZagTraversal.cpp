  void level_order(Node* root,vector<int>&ans)
  {
      queue<Node*>q;
      q.push(root);
      int level=0;
      vector<int>traverse;
      while(!q.empty())
      {
          int size=q.size();
          level++;
          for(int i=0;i<size;i++)
          {
              traverse.push_back(q.front()->data);
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
          if(level&1)
          {
              for(int i=0;i<traverse.size();i++)
              {
                  ans.push_back(traverse[i]);
              }
          }
          else
          {
              reverse(traverse.begin(),traverse.end());
              for(int i=0;i<traverse.size();i++)
              {
                  ans.push_back(traverse[i]);
              }
          }
         traverse.erase(traverse.begin(),traverse.end());
         
      }
      
  }
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector <int> ans;
    	level_order(root,ans);
    	return ans;
    	
    }
