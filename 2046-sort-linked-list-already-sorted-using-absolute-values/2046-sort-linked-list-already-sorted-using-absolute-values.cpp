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
    ListNode* sortLinkedList(ListNode* head) {
        ListNode*pre=head,*cur=head->next;
        while(cur){
            if(cur->val<0){
                ListNode*next=cur->next;
                pre->next=next;
                cur->next=head;
                head=cur;
                cur=next;
            }else{
                pre=cur;
                cur=cur->next;
            }
        }
        return head;
    }
};