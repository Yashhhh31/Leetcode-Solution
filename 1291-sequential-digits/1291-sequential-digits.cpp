class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;

        for(int i=1; i<=8; i++){
            q.push(i);
        }

        vector<int> result;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();

            if(front >= low && front <= high){
                result.push_back(front);
            } else if(front > high){
                break;
            }

            int last_digit = front % 10;

            if(last_digit + 1 > 9) continue;
            
            q.push(front*10 + (last_digit + 1));
        }

        return result;
    }
};