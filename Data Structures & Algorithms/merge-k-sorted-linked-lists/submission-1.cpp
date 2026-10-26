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
    struct comp{
        bool operator()( ListNode *&x,  ListNode *&y)
        {
            return x->val>y->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, comp> pq; 
        for(ListNode *list:lists)
        {
            if(list)
                pq.push(list);
        }
        ListNode *hhead=new ListNode(-1);
        ListNode *temp=hhead;
        while(!pq.empty())
        {
            temp->next=pq.top();
            pq.pop();
            temp=temp->next;
            if(temp->next)
                pq.push(temp->next);
        }
        return hhead->next;
    }
};
