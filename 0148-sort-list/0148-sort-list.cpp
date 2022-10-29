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
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next)
            return head;
        ListNode*f=head,*s=head,*p=head;                
        while(f and f->next){
            f=f->next->next;
            p=s;
            s=s->next;
        }
        p->next=nullptr;
        ListNode*l=sortList(head),*r=sortList(s),d;
        p=&d;
        while(l or r){
            if(!l or (r and r->val<l->val)){// or r->val<l->val){
                p->next=r;
                r=r->next;
            }else if(!r or l->val<=r->val){
                p->next=l;
                l=l->next;
            }
            p=p->next;
        }
        p->next=nullptr;
        return d.next;
    }
};