class Solution {
public:

    int maxPath;

    int solve(TreeNode* root){

        if(!root)
            return 0;

        int l = max(0,solve(root->left));
        int r = max(0,solve(root->right));

        maxPath = max(maxPath, l + r + root->val);

        return max(l,r) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        
        maxPath = INT_MIN;
        solve(root);

        return maxPath;

    }
};