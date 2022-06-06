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
    ListNode *getIntersectionNode(ListNode *hA, ListNode *hB) {
        ListNode*c0=hA,*c1=hB;
        while(c0 and c1){
            c0=c0->next;
            c1=c1->next;
        }
        if(c0)
            c1=hA;
        else
            c0=hB;
        while(c0 and c1){
            c0=c0->next;
            c1=c1->next;
        }
        if(c0)
            c1=hA;
        else
            c0=hB;
        while(c0 and c1 and c0!=c1){
            c0=c0->next;
            c1=c1->next;
        }
        if(c0==c1)
            return c0;
        return nullptr;
    }
};