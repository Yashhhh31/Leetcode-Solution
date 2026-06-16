class Solution {
public:
    string processStr(string s) {
        string result = "";

        for(char &ch : s){
            if(ch == '*'){
                if(result.size() > 0){
                    result.pop_back();
                }else{
                    continue;
                }
            }else if(ch == '#'){
                result += result;
            }else if(ch == '%'){
                reverse(result.begin(), result.end());
            }else{
                result += ch;
            }
        }


        return result;
    }
};