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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next)
            return head;
        ListNode dummy,*pre=&dummy,*cur=head;
        while(cur and cur->next){
            ListNode *first=cur,*second=cur->next,*next=cur->next->next;
            pre->next=second;//d->2//d->2->1->4
            second->next=first;//d->2->1//d->2->1->4->3
            first->next=next;//d->2->1->3//d->2->1->4->3->N

            pre=cur;//1
            cur=next;//3
        }
        return dummy.next;
    }
};