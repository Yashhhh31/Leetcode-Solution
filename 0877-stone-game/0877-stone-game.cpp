class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        priority_queue<int> pq(piles.begin(),piles.end());

        int cnt1 = 0;
        int cnt2 = 0;
        bool flag = false;

        while(!pq.empty()){
            if(flag){
                cnt2 += pq.top();
                pq.pop();
                flag = !flag; 
            }else{
                cnt1 += pq.top();
                pq.pop();
                flag = !flag;
            }
        }

        return cnt1 > cnt2;
    }
};