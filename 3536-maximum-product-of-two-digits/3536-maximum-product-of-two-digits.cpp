class Solution {
public:
    int maxProduct(int n) {
        int largest = 0;
        int second = 0;

        while(n > 0){
            int digit = n%10;

            if(digit >= largest){
                second = largest;
                largest = digit;
            }else if(digit > second && digit < largest){
                second = digit;
            }

            n /= 10;
        }

        return second*largest;
    }
};