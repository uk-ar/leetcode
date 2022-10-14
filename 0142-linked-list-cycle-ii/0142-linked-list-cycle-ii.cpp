/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head or !head->next)
            return nullptr;
        ListNode*f=head->next->next,*s=head->next;
        while(f and f->next and f!=s){
            f=f->next->next;
            s=s->next;
        }
        if(f!=s)
            return nullptr;
        f=head;
        while(f!=s){
            f=f->next;
            s=s->next;
        }
        return s;
    }
};