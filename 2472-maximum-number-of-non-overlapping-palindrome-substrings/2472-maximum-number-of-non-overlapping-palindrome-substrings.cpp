class Solution {
public:

    int n;
    vector<vector<int>> dp;

    bool isPalindrome(string &s, int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    int solve(string &s, int i, int j, int k){

        if(i >= n || j >= n)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        

        if(isPalindrome(s, i, j)){
            return dp[i][j] = 1 + solve(s, j+1, j+k, k);
        }

        int grow = solve(s, i, j+1, k);
        int slide = solve(s, i+1, j+1, k);

        return dp[i][j] = max(grow, slide);
    }

    int maxPalindromes(string s, int k) {
        n = s.length();

        if(k > n)
            return 0;
        

        if(k == 1)
            return n;
        
        dp.assign(n, vector<int>(n, -1));

        return solve(s, 0, k-1, k);
        
    }
};