class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        
        int n = word1.length();
        int m = word2.length();

        vector<int> rightHandMatched(n);

        int i = n-1;
        int j = m-1;
        int matched = 0;

        while(i >= 0){

            if(j >= 0 && word1[i] == word2[j]){
                matched++;
                j--;
            }

            rightHandMatched[i] = matched;
            i--;
        }

        i = 0;
        j = 0;
        bool change = false;
        vector<int> seq;

        while(i < n && j < m){
            if(word1[i] == word2[j]){
                seq.push_back(i);
                j++;
            }else if(!change && i+1 < n && rightHandMatched[i+1] >= m - j - 1){
                change = true;
                seq.push_back(i);
                j++;
            }

            i++;
        }

        return (j == m) ? seq : vector<int> ();

    }
};