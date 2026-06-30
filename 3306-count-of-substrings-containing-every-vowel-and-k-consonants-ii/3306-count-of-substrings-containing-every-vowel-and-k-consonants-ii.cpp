class Solution {
public:

    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.length();

        unordered_map<char,int> mp;

        vector<int> prev(n);
        int lastSeenConsonant = n;

        for(int i=n-1; i>=0; i--){
            prev[i] = lastSeenConsonant;

            if(!isVowel(word[i])){
                lastSeenConsonant = i;
            }
        }

        long long count = 0;
        int l = 0; 
        int r = 0;
        int consonent = 0;

        while(r < n){
            char ch = word[r];

            if(isVowel(ch)){
                mp[ch]++;
            }else{
                consonent++;
            }

            while(consonent > k){
                char ch = word[l];

                if(isVowel(ch)){
                    mp[ch]--;
                }else{
                    consonent--;
                }

                if(mp[ch] == 0){
                    mp.erase(ch);
                }

                l++;
            }

            while(mp.size() >= 5 && consonent == k){
                count += prev[r] - r;

                if(isVowel(word[l])){
                    mp[word[l]]--;
                }else{
                    consonent--;
                }

                if(mp[word[l]] == 0){
                    mp.erase(word[l]);
                }

               l++;
            }

            r++;
        }

        return count;
    }
};