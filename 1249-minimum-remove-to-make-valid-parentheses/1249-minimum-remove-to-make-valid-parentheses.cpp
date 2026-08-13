class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        int open = 0;
        string temp = "";

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                open++;
                temp.push_back(s[i]);
            }else if(s[i] == ')'){
                if(open > 0){
                    open--;
                    temp.push_back(s[i]);
                }
                
            }else{
                temp.push_back(s[i]);
            }
        }

        string result = "";


        for(int i=temp.length()-1; i>=0; i--){
            if(temp[i] == '(' && open > 0){
                open--;
            }else{
                result.push_back(temp[i]);
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }
};