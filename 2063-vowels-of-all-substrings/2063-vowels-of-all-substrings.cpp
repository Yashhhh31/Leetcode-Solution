class Solution {
public:
    
    bool isVowel(char &ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    long long countVowels(string word) {
        int n = word.length();

        int r = 0;
        long long cnt = 0;

        while(r < n){
            if(isVowel(word[r])){
                cnt += 1ll * (r+1) * (n-r);
            }
            r++;
        }

        return cnt;
    }
};

//abaab  5+9+8