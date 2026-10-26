/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node *temp=head;
        while(temp)
        {
            Node *newtemp=new Node(temp->val);
            newtemp->next=temp->next;
            temp->next=newtemp;
            temp=newtemp->next;
        }

        temp=head;
        while(temp)
        {
            if(temp->random)
            {
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }

        temp=head;
        Node *newhead=head->next;
        Node *newtemp=newhead;

        while(temp)
        {
            temp->next=temp->next->next;
            temp=temp->next;
            if(newtemp->next)
            {
                newtemp->next=newtemp->next->next;
                newtemp=newtemp->next;
            }
        }

        return newhead;
    }
};
