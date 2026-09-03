class Solution {
public:
    vector<string> ans;

    void solve(int n, string &s, int open,int close){
        if(s.length() >= n*2){
            ans.push_back(s);
        }

        if(open < n){
            s.push_back('(');
            solve(n,s,open+1,close);
            s.pop_back();
        }

        if(close < open){
            s.push_back(')');
            solve(n,s,open,close+1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        int open = 0;
        int close = 0;
        solve(n,s,open,close);

        return ans;
    }
};