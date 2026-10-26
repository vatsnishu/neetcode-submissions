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
    ListNode *reverse(ListNode *head)
    {
        ListNode *cur=head;
        ListNode *prev=NULL;
        while(cur)
        {
            ListNode *next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *revhead=slow->next;
        slow->next=NULL;
        revhead=reverse(revhead);
        ListNode *revtemp=revhead;
        ListNode *temp=head;
        while(revtemp)
        {
            ListNode *next=temp->next;
            ListNode *revnext=revtemp->next;
            temp->next=revtemp;
            revtemp->next=next;
            temp=next;
            revtemp=revnext;
        }
    }
};
