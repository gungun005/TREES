class Solution {
  public:
  void traversal_left(Node *root,vector<int>&ans)
  {
        if(root==NULL || (root->left==NULL && root->right==NULL))
        {
            return ;
        }
        ans.push_back(root->data);
        if(root->left)
        {
            traversal_left(root->left,ans);
        }
        else
        {
        traversal_left(root->right,ans);
        }
  }
  void traversal_leaf(Node *root,vector<int>&ans)
  {
      if(root==NULL)
      {
          return;
      }
      if(root->left ==NULL && root->right==NULL)
      {
          ans.push_back(root->data);
      }
      traversal_leaf(root->left,ans);
      traversal_leaf(root->right,ans);
  }
    void traversal_right(Node *root,vector<int>&ans)
        {
        if(root==NULL || (root->left==NULL && root->right==NULL))
        {
            return ;
        }
        if(root->right)
        {
            traversal_right(root->right,ans);
        }
        else
        {
        traversal_right(root->left,ans);
        }
        ans.push_back(root->data);
  }
  
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL)
        {
            return ans;
        }
        ans.push_back(root->data);
        //traversing left subtree
        traversal_left(root->left,ans);
        //traversing leaf nodes
        //leaf nodes in left subtree
        traversal_leaf(root->left,ans);
        //leaf nodes in right subtree
        traversal_leaf(root->right,ans);
        //traversing right subtree
        traversal_right(root->right,ans);
        return ans;
        
    }
