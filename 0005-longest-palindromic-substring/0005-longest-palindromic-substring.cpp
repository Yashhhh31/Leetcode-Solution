class Solution {
public:

    bool isSafe(int i, int j, string &s,vector<vector<int>> &dp){
        if(i >= j){
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]){
            return dp[i][j] = isSafe(i+1,j-1,s,dp);
        }
        return dp[i][j] = 0;
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 0) return "0";
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        int st;
        int maxlen = 0;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isSafe(i,j,s,dp) == true){
                   if(j-i+1 > maxlen){
                        maxlen = j-i+1;
                        st = i;
                   }
                }
            }
        }

        return s.substr(st,maxlen);
    }
};