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
    ListNode* oddEvenList(ListNode* head) {
        ListNode oh,eh,*o=&oh,*e=&eh;
        while(head and head->next){
            o->next=head;
            o=o->next;
            e->next=head->next;
            e=e->next;
            head=head->next->next;
        }
        if(head){
            o->next=head;
            o=o->next;
        }
        e->next=nullptr;
        o->next=eh.next;
        return oh.next;
    }
};