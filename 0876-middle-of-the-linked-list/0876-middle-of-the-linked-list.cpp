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
    ListNode* middleNode(ListNode* head) {
        // 123
        //s^
        //f ^
        // 12
        //s^
        //f ^
        if(!head or !head->next)
            return head;
        ListNode*fast=head,*slow=head;
        while(fast and fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};