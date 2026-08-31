class Solution {
public:
    int ladderLength(string beginWord, string end, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        unordered_set<string> visited;

        queue<string> que;
        que.push(beginWord);
        visited.insert(beginWord);
        int cnt = 1;


        while(!que.empty()){
            int size = que.size();

            while(size--){
                string word = que.front();
                que.pop();

                if(word == end){
                    return cnt;
                }

                for(char ch = 'a'; ch <= 'z'; ch++){
                    for(int i=0; i<word.length(); i++){
                        string nextWord = word;
                        nextWord[i] = ch;

                        if(!visited.count(nextWord) && st.count(nextWord)){
                            que.push(nextWord);
                            visited.insert(nextWord);
                        }
                    }
                }
            }

            cnt++;
        }

        return 0;

    }
};