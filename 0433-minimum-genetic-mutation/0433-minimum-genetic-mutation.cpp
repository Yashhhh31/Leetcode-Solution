class Solution {
public:
    int minMutation(string startGene, string end, vector<string>& bank) {
        int n = startGene.length();

        unordered_set<string> st(bank.begin(), bank.end());
        unordered_set<string> visited;

        queue<string> q;
        q.push(startGene);
        visited.insert(startGene);
        int cnt = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                string word = q.front();
                q.pop();

                if(word == end){
                    return cnt;
                }

                for(char ch : "ACGT"){
                    for(int i=0; i<word.size(); i++){
                        string nextWord = word;
                        nextWord[i] = ch;

                        if(!visited.count(nextWord) && st.count(nextWord)){
                            q.push(nextWord);
                            visited.insert(nextWord);
                        }
                    }
                }
            }

            cnt++;
        }

        return -1;

    }
};