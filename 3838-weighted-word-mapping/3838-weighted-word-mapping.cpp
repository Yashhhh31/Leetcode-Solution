class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";

        for(string &word : words){
            int total = 0;
            for(char& ch : word){
                total += weights[ch - 'a'];
            }

            result += 'z' - total % 26;
        }

        return result;
    }
};