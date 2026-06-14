/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* left = head;

        int cnt = 0;
        stack<int> s;

        ListNode* temp = head;
        while(temp != NULL){
            s.push(temp->val);
            temp = temp->next;
            cnt++;
        }

        cnt /= 2;

        int maxSum = INT_MIN;
        while(cnt > 0){
            int right = s.top();
            s.pop();
            maxSum = max(right + left->val,maxSum);
            left = left -> next;
            cnt--;
        }

        return maxSum;
    }
};