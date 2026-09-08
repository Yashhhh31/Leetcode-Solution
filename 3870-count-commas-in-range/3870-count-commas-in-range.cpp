class Solution {
public:
    int countCommas(int n) {
        string s = to_string(n);
        int cnt = 0;

        if(s.length() > 5){
            cnt += n - 99999;

            
        }

        if(s.length() > 3){
            cnt += n - 999 - cnt;
        }

        return cnt;
    }
};