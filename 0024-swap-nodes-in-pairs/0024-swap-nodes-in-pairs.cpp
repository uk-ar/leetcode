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
            pre->next=cur->next;//d->2 1->4            
            ListNode *next=cur->next->next;//3      
            cur->next->next=cur;//2->1
            cur->next=next;//important!
            pre=cur;//1
            cur=next;//3
        }
        return dummy.next;
    }
};