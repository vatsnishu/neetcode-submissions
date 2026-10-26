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
    bool shouldReverse(ListNode *head, int k)
    {
        int len=0;
        while(head)
        {
            head=head->next;
            len++;
            if(len==k)
                return true;
        }
        return false;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return NULL;
        if(!shouldReverse(head, k))
            return head;
        ListNode *prev=NULL;
        ListNode *cur=head;
        for(int i=0;i<k;i++)
        {
            ListNode *next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        head->next=reverseKGroup(cur, k);
        return prev;
    }
};
