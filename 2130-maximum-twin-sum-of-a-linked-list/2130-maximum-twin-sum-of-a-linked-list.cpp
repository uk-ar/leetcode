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
    ListNode *rev(ListNode*head){
        ListNode*pre=nullptr;
        while(head){
            ListNode*next=head->next;
            head->next=pre;
            pre=head;
            head=next;            
        }
        return pre;
    }
    int pairSum(ListNode* head) {
        ListNode*f=head,*s=head;
        while(f and f->next){
            f=f->next->next;
            s=s->next;
        }
        s=rev(s);
        int ans=INT_MIN;
        while(s){
            ans=max(ans,s->val+head->val);
            s=s->next;
            head=head->next;
        }
        return ans;
    }
};