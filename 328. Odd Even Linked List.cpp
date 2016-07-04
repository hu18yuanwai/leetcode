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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return head;
        ListNode* evenNode=head->next;
        ListNode* oddCur=head;
        ListNode* evenCur=evenNode;
        ListNode* cur=head->next->next;
        int i=1;
        while(cur){
        	if(i%2){
        		oddCur->next=cur;
        		oddCur=oddCur->next;
        	}
        	else{
        		evenCur->next=cur;
        		evenCur=evenCur->next;
        	}
        	i++;
        	cur=cur->next;
        }
        oddCur->next=evenNode;
        evenCur->next=NULL;
        return head;
    }
};