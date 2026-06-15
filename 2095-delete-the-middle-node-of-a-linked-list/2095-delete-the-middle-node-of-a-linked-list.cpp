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
    ListNode* deleteMiddle(ListNode* head) {

        if(head == NULL || head->next == NULL) return NULL;
        int cnt = 0;
        ListNode* temp = head;

        while(temp != NULL){
            temp = temp->next;
            cnt++;
        }

        cnt = cnt/2;
        temp = head;
        while(cnt > 1){
            temp = temp->next;
            cnt--;
        }

        temp->next = temp->next->next;

        return head;
    }
};