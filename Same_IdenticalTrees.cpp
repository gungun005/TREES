class Solution {
public:
bool check(TreeNode* p, TreeNode* q)
{
    if(p==NULL && q==NULL)
    {
        return true;
    }
    else if(p==NULL || q==NULL)
    {
        return false;
    }
    else if(p->val==q->val && check(p->left,q->left) && check(p->right,q->right))
    {
        return true;
    }
    return false;
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p,q);
    }
};
