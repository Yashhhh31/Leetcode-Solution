class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int count = 0;

        int hash[3] = {-1,-1,-1};

        for(int r=0; r<s.length(); r++){
            hash[s[r]-'a'] = r;

            count = count + (1 + min({hash[0],hash[1],hash[2]}));
        }

        return count;
    }
};