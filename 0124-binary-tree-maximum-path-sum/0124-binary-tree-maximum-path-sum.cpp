class Solution {
public:

    int maxPath;

    int solve(TreeNode* root){

        if(!root)
            return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        int neeche_hi_mill_gya_answer =  l + r + root->val;
        int koi_ek_aacha = max(l,r) + root->val;
        int only_root_aacha = root->val;

        maxPath = max({maxPath, neeche_hi_mill_gya_answer, koi_ek_aacha, only_root_aacha});

        return max(only_root_aacha, koi_ek_aacha);
    }

    int maxPathSum(TreeNode* root) {
        
        maxPath = INT_MIN;
        solve(root);

        return maxPath;

    }
};