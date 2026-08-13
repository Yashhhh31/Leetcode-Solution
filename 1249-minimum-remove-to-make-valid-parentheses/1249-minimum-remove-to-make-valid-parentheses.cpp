class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();

        stack<int> st;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                }else{
                    s[i] = '#';
                }
            }
        }

        while(!st.empty()){
            s[st.top()] = '#';
            st.pop();
        }

        string result = "";

        for(char& c : s){
            if(c != '#'){
                result.push_back(c);
            }
        }

        return result;
    }
};