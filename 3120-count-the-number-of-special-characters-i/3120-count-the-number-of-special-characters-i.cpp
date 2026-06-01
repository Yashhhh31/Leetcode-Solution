class Solution {
public:
    int numberOfSpecialChars(string word) {
        int freq[123] = {0};

        for(char &ch : word){
            freq[ch]++;
        }

        int cnt = 0;
        for(char ch = 'a'; ch <= 'z'; ch++){
            char capital = ch - 'a' + 'A';

            if(freq[ch] > 0 && freq[capital] > 0) cnt++;
        }

        return cnt;
    }
};