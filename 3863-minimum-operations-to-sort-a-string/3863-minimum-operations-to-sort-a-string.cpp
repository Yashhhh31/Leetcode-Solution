class Solution {
public:
    int minOperations(string s) {
        
        int n = s.length();

        if(is_sorted(begin(s), end(s))){
            return 0;
        }

        if(n == 2)
            return -1;

        int min_ele =  0, max_ele = 0;

        for(int i=1; i<n; i++){

            if(s[i] >= s[max_ele]){
                max_ele = i;
            }
            
            if(s[i] < s[min_ele]){
                min_ele = i;
            }
        }

        if(min_ele == 0 || max_ele == n-1){
            return 1;
        }

        if(min_ele == n-1 && max_ele == 0){
            return 3;
        }

        return 2;

    }
};