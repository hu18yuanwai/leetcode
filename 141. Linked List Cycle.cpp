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
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode *p1=head,*p2=head;
        while(p1 && p2){
        	p1=p1->next;
        	p2=p2->next;
        	if(p2==NULL) return false;
        	p2=p2->next;
        	if(p1==p2) return true;
        }
        return false;
    }
};