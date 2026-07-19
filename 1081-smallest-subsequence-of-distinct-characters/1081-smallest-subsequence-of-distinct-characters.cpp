class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<int> lastIdx(26);

        for(int i=0; i<n; i++){
            lastIdx[s[i] - 'a'] = i;
        }

        vector<bool> visited(26, false);
        string result = "";

        for(int i=0; i<n; i++){
            char ch = s[i];

            if(visited[ch - 'a']){
                continue;
            }

            while(i < n && result.length() > 0 && result.back() > ch && lastIdx[result.back() - 'a'] > i){
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return result;

    }
};