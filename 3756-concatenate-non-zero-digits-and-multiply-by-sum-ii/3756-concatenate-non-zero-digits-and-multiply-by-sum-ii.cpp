class Solution {
public:

    int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();

        vector<int> numberUpTo(n);
        vector<long long> sumUpTo(n);
        vector<long long> nonZeroDigitUpTo(n);
        vector<long long> pow10(n+1);
        vector<int> result;

        int cnt = 0;
        int cumSum = 0;
        int i = 0;
        long long number  = 0;
        long long pow = 1;

        for(char &ch : s){
            int num = ch - '0';
            if(num > 0){
                cnt++;
                cumSum += num;
                number = (number*10 + num) % MOD;
            }

            nonZeroDigitUpTo[i] = cnt;
            sumUpTo[i] = cumSum;
            numberUpTo[i] = number;
            pow10[i] = pow;
            pow = pow * 10 % MOD;

            i++;
        }

        pow10[i] = pow;

        for(vector<int>& q : queries){
            int l = q[0];
            int r = q[1];
            long long  sum = sumUpTo[r];
            long long x = numberUpTo[r];
            int k = nonZeroDigitUpTo[r];

            if(l > 0){
                sum -= sumUpTo[l-1];
                k -= nonZeroDigitUpTo[l-1];
                x = (x - (numberUpTo[l-1]*pow10[k] % MOD) + MOD) % MOD;
            } 

            result.push_back((1LL * sum * x) % MOD);
        } 

        return result;
    }
};