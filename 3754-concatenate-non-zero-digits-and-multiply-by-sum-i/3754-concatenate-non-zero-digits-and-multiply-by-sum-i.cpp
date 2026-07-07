class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        long long pow10 = 1;

        while(n > 0){
            int rem = n%10;
            if(rem != 0){
                x += rem*pow10;
                pow10 *= 10;
                sum += rem;
            }

            n /= 10;
        }

        return x * sum;
    }
};