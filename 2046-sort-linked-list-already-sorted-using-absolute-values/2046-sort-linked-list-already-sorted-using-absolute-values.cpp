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
    ListNode* rev(ListNode*head){
        ListNode*pre=nullptr;
        while(head){
            ListNode*next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
    ListNode* sortLinkedList(ListNode* head) {
        if(!head)
            return head;
        ListNode dp,dn,*pos=&dp,*neg=&dn;
        while(head){
            ListNode *next=head->next;
            head->next=nullptr;
            if(head->val>=0){
                pos->next=head;                
                pos=pos->next;
            }else{
                neg->next=head;
                neg=neg->next;
            }
            head=next;
        }
        head=rev(dn.next);
        if(dn.next){
            dn.next->next=dp.next;
        //rev(dn.next);
            return head;
        }
        return dp.next;
    }
};