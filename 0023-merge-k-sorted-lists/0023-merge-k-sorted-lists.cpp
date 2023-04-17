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
    ListNode* mergeKLists(vector<ListNode*>& li) {
        priority_queue<pair<int,ListNode*>>q;
        
        for(auto n:li){
            if(n)
                q.push({-n->val,n});
        }
        ListNode d,*c=&d;
        while(q.size()>0){
            auto [_,n]=q.top();q.pop();
            c->next=n;
            c=c->next;
            if(n->next)
                q.push({-n->next->val,n->next});
        }
        return d.next;
    }
};